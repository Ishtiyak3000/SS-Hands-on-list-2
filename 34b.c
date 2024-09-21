/*
 ============================================================================================
  Name: 34b.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:Write a program to create a concurrent server.
  b. use pthread_create
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    free(arg); 
    char buffer[BUFFER_SIZE];
    int valread = read(client_socket, buffer, BUFFER_SIZE);
    buffer[valread] = '\0';
    printf("Message from client: %s\n", buffer);
    char *response = "Message received!";
    send(client_socket, response, strlen(response), 0);
    printf("Response sent to client.\n");
    close(client_socket);
    return NULL;
}

int main() {
    int server_fd, *client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
    
        client_socket = malloc(sizeof(int));
        if ((*client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            free(client_socket);
            continue;
        }

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, client_socket) != 0) {
            perror("pthread_create failed");
            free(client_socket);
            continue;
        }
        pthread_detach(thread_id);
    }

    close(server_fd);
    return 0;
}