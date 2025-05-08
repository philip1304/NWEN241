#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define BUFFER_SIZE 1024

// Function to trim trailing newline characters
void trim_newline(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

// Signal handler to avoid zombie processes
void sigchld_handler(int s) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    send(client_sock, "HELLO\n", 6, 0);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes <= 0) break;

        trim_newline(buffer);

        if (strcasecmp(buffer, "BYE") == 0) {
            close(client_sock);
            break;
        } else if (strncasecmp(buffer, "GET ", 4) == 0) {
            char *filename = buffer + 4;
            FILE *fp = fopen(filename, "r");
            if (fp) {
                send(client_sock, "SERVER 200 OK\n\n", 16, 0);
                char line[BUFFER_SIZE];
                while (fgets(line, sizeof(line), fp)) {
                    send(client_sock, line, strlen(line), 0);
                }
                send(client_sock, "\n\n", 2, 0);
                fclose(fp);
            } else {
                send(client_sock, "SERVER 404 Not Found\n", 22, 0);
            }
        } else if (strncasecmp(buffer, "PUT ", 4) == 0) {
            char *filename = buffer + 4;
            FILE *fp = fopen(filename, "w");
            if (!fp) {
                send(client_sock, "SERVER 501 Put Error\n", 22, 0);
                continue;
            }

            int empty_line_count = 0;
            while (1) {
                memset(buffer, 0, sizeof(buffer));
                int bytes = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
                if (bytes <= 0) break;

                buffer[bytes] = '\0';

                if (strcmp(buffer, "\n") == 0 || strcmp(buffer, "\r\n") == 0) {
                    empty_line_count++;
                } else {
                    empty_line_count = 0;
                }

                fputs(buffer, fp);
                if (empty_line_count == 2) break;
            }

            fclose(fp);
            send(client_sock, "SERVER 201 Created\n", 20, 0);
        } else {
            send(client_sock, "SERVER 502 Command Error\n", 26, 0);
        }
    }

    close(client_sock);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return -1;
    }

    int port = atoi(argv[1]);
    if (port < 1024) {
        fprintf(stderr, "Port must be >= 1024\n");
        return -1;
    }

    signal(SIGCHLD, sigchld_handler); // Clean up child processes

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in server_addr = {0}, client_addr = {0};
    socklen_t client_len = sizeof(client_addr);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_sock);
        return -1;
    }

    if (listen(server_sock, 5) < 0) {
        perror("listen");
        close(server_sock);
        return -1;
    }

    printf("Server listening on port %d...\n", port);

    while (1) {
        int client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            send(client_sock, "HELLO\n", 6, 0);
            close(client_sock);
        } else if (pid == 0) {
            // Child process
            close(server_sock);
            handle_client(client_sock);
        } else {
            // Parent process
            close(client_sock);
        }
    }

    close(server_sock);
    return 0;
}
