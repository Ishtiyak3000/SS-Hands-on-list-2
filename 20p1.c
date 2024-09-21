/*
 ============================================================================================
  Name: 20p1.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:  Write two programs so that both can communicate by FIFO -Use one way communication.
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    char *fifo_name = "my_fifo";
    mkfifo(fifo_name, 0666);
    char message[100];
    while (1) {
        printf("Enter a message[type 'terminate' for exiting]: ");
        fgets(message, sizeof(message), stdin); 
        int fd = open(fifo_name, O_WRONLY);
        message[strcspn(message, "\n")] = 0;
        if (strcmp(message, "terminate") == 0) {
            write(fd, message, strlen(message) + 1);
            break;
        }
        
        write(fd, message, strlen(message) + 1);
        close(fd);
    }
    unlink(fifo_name);
    return 0;
}
