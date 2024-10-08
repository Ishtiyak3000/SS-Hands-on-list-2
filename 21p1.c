/*
 ============================================================================================
  Name: 21p1.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:  Write two programs so that both can communicate by FIFO -Use two way communication.
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    const char *fifo1 = "fifo1"; 
    const char *fifo2 = "fifo2";
    mkfifo(fifo1, 0666);
    char message[100];
    char response[100];
    while (1) {
        printf("Sender: Enter a message (type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0;
        if (strcmp(message, "exit") == 0) {
            break;
        }
        int fd_send = open(fifo1, O_WRONLY);
        write(fd_send, message, strlen(message) + 1);
        close(fd_send);
        int fd_receive = open(fifo2, O_RDONLY);
        read(fd_receive, response, sizeof(response));
        printf("Receiver: %s\n", response);
        close(fd_receive);
    }
    unlink(fifo1);
    return 0;
}
