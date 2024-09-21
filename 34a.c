/*
 ============================================================================================
  Name: 34a.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:Write a program to create a concurrent server.
  a. use fork
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int valread;

    // Read message from client
    valread = read(client_socket, buffer, BUFFER_SIZE);
    buffer[valread] = '\0'; // Null-terminate the string
    printf("Message from client: %s\n", buffer);

    // Send a response back to the client
    const char *response = "Message received!";
    send(client_socket, response, strlen(response), 0);
    printf("Response sent to client.\n");

    // Close the client socket
    close(client_socket);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Binding the socket to the specified port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accepting a connection
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            continue;
        }

        // Fork a new process to handle the client
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            close(client_socket);
        } else if (pid == 0) {
            // Child process
            close(server_fd); // Close the listening socket in child
            handle_client(client_socket);
            exit(0); // Exit child process
        } else {
            // Parent process
            close(client_socket); // Close the connected socket in parent
        }

        // Optionally clean up terminated child processes
        while (waitpid(-1, NULL, WNOHANG) > 0);
    }

    close(server_fd);
    return 0;
}