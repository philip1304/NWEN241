#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 23456
#define BUFFER_SIZE 1024

// Function to reverse a string in-place
void reverse_string(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to the specified port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept a client connection
        client_fd = accept(server_fd, NULL, NULL);

        if (client_fd < 0) {
            perror("Accept failed");
            continue;
        }

        // Clear buffer and read data
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = read(client_fd, buffer, BUFFER_SIZE - 1);

        if (bytes_read < 0) {
            perror("Read failed");
            close(client_fd);
            continue;
        }

        // Remove newline if present
        buffer[strcspn(buffer, "\n")] = '\0';

        // Reverse the string
        reverse_string(buffer);

        // Send back the reversed string
        write(client_fd, buffer, strlen(buffer));

        // Close the client connection
        close(client_fd);
    }

    // Close the server socket (unreachable in this loop)
    close(server_fd);
    return 0;
}
