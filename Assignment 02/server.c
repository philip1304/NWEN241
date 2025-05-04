/**
 * Skeleton file for server.c
 * 
 * You are free to modify this file to implement the server specifications
 * as detailed in Assignment 3 handout.
 * 
 * As a matter of good programming habit, you should break up your imple-
 * mentation into functions. All these functions should contained in this
 * file as you are only allowed to submit this file.
 */ 

// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Size of the buffer for data transmission
#define BUFFER_SIZE 1024

// Response macros for standardized server replies
#define MSG_HELLO "HELLO\n"
#define MSG_200 "SERVER 200 OK\n\n"
#define MSG_201 "SERVER 201 Created\n"
#define MSG_404 "SERVER 404 Not Found\n"
#define MSG_500 "SERVER 500 Get Error\n"
#define MSG_501 "SERVER 501 Put Error\n"
#define MSG_502 "SERVER 502 Command Error\n"

/**
 * Sends a complete string message to the specified socket.
 * 
 * @param sock - The socket file descriptor to send data to.
 * @param msg  - The null-terminated string to send.
 */
void send_message(int sock, const char *msg) {
    send(sock, msg, strlen(msg), 0);
}

/**
 * Removes trailing newline characters from a string.
 * 
 * @param buffer - The input string buffer to the modified in-place.
 */
void trim_newline(char *buffer) {
    // Replaces newline with null terminator
    buffer[strcspn(buffer, "\r\n")] = '\0';
}

/**
 * Handles the GET command from the client.
 * Sends the contents of the requested file if it exists.
 * 
 * @param client_sock - The client socket to communicate through.
 * @param filename    - The name of the file to retrieve.
 */
void handle_get(int client_sock, const char *filename) {
    // If filename is empty
    if (filename[0] == '\0') {
        send_message(client_sock, MSG_500);
        return;
    }

    // Open file in read mode
    FILE *fp = fopen(filename, "r");

    if (fp) {
        send_message(client_sock, MSG_200); // Notify client that file is found
        char line[BUFFER_SIZE];

        // Read file line by line and send to client
        while (fgets(line, sizeof(line), fp)) {
            send(client_sock, line, strlen(line), 0);
        }

        send_message(client_sock, "\n\n");  // Send double newline to mark end
        fclose(fp);
    }
    else {
        send_message(client_sock, MSG_404); // File not found
    }
}

/**
 * Handles the PUT command from the client.
 * Receives content and saves it to the specified file.
 * Terminates input on receiving two consecutive newlines.
 * 
 * @param client_sock - The client socket to receive data from.
 * @param filename    - The name of the file to create/write.
 */
void handle_put(int client_sock, const char *filename) {
    // If filename is empty
    if (filename[0] == '\0') {
        return;
    }

    // Open file in write mode
    FILE *fp = fopen(filename, "w");

    if (!fp) {
        send_message(client_sock, MSG_501); // Error opening file
        return;
    }

    char buffer[BUFFER_SIZE];
    int newline_count = 0; // Tracks number of consecutive newlines

    // Receive data until two consecutive newlines are received
    while (1) {
        int n = recv(client_sock, buffer, sizeof(buffer) - 1, 0);

        // Client disconnected or error
        if (n <= 0) {
            break; // Exit on error or disconnection
        }

        buffer[n] = '\0';  // Null-terminate buffer
        fputs(buffer, fp); // Write to file

        // Check for two consecutive newline characters
        for (int i = 0; i < n; i++) {
            if (buffer[i] == '\n') {
                newline_count++;

                if (newline_count == 2) {
                    break;             // End of message
                }
                else {
                    newline_count = 0; // Reset if non-newline found
                }
            }
        }

        // Exit on double newline
        if (newline_count == 2) {
            break; 
        }
    }

    fclose(fp);
    send_message(client_sock, MSG_201);
}

/**
 * Parses and processes client commands: BYE, GET, PUT.
 * Sends appropriate responses or invokes file handlers.
 * 
 * @param client_sock - The client socket associated with the current connection.
 * @param buffer      - The command string received from the client.
 */
void process_client_command(int client_sock, char *buffer) {
    trim_newline(buffer);

    if (strcasecmp(buffer, "BYE") == 0) {
        close(client_sock); // Close the socket
        exit(0);            // Terminate server (single-client version)
    }
    else if (strncasecmp(buffer, "GET ", 4) == 0) {
        handle_get(client_sock, buffer + 4); // Pass filename to GET handler
    }
    else if (strncasecmp(buffer, "PUT ", 4) == 0) {
        handle_put(client_sock, buffer + 4); // Pass filename to PUT handler
    }
    else {
        send_message(client_sock, MSG_502); // Unknown command
    }
}

/**
 * Entry point of the server program.
 * Sets up TCP pocket, listens for one client, and handles simple requests.
 * 
 * @param argc - Number of command-line arguments (must be 2).
 * @param argv - Argument vector (expects port number as argv[1]).
 * @return     - Exit status of the program.
 */
int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return -1;
    }

    // Convert port argument to integer
    int port = atoi(argv[1]);

    // Port must be >= 1024 to avoid restricted ports
    if (port < 1024) {
        fprintf(stderr, "Port number must be >= 1024.\n");
        return -1;
    }

    // Create TCP socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock < 0) {
        perror("socket"); // Print error if socket creation fails
        return -1;
    }

    // Bind socket to port
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));   // Zero out the struct for safety
    server_addr.sin_family = AF_INET;           // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;   // Accepts connections from any interface
    server_addr.sin_port = htons(port);         // Convert port to network byte order

    if (bind(server_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_sock);
        return -1;
    }

    // Start listening for incoming connections (max 5 queued)
    if (listen(server_sock, 5) < 0) {
        perror("listen");
        close(server_sock);
        return -1;
    }

    printf("Server listening on port %d...\n", port);

    // Accept a single client connection
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(server_sock, (struct sockaddr*) &client_addr, &client_len);

    if (client_sock < 0) {
        perror("accept");
        close(server_sock);
        return -1;
    }

    // Print connected client's IP and port
    printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // HELLO
    send_message(client_sock, MSG_HELLO);

    // Loop to receive and process client commands
    char buffer[BUFFER_SIZE];

    while (1) {
        // Receive message from client
        int bytes_received = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            break; // Exit loop if client disconnects
        }

        buffer[bytes_received] = '\0';               // Null-terminate received data
        process_client_command(client_sock, buffer); // Handle command
    }

    // Close sockets after client disconnects
    close(client_sock);
    close(server_sock);

    return 0;
}

