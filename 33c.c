/*
 ============================================================================================
  Name: 33c.c
  Author: Ishtiyak Ahmad Khan
  Date : 20 SEPT 2024
  Description: Write a program to communicate between two machines using socket
  ============================================================================================
*/ 
//                                client side
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from i am ishtiyak!";
    char buffer[BUFFER_SIZE] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock, message, strlen(message), 0);
    printf("Message sent to server.\n");
    read(sock, buffer, BUFFER_SIZE);
    printf("Response from server: %s\n", buffer);
    close(sock);
    return 0;
}