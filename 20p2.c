/*
 ============================================================================================
  Name: 20p2.c
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
    char message[100];
    while (1) {
        int fd = open(fifo_name, O_RDONLY);
        read(fd, message, sizeof(message));
        if (strcmp(message, "terminate") == 0) {
            break;
        }
        printf("Received: %s\n", message);
        close(fd);
    }

    return 0;
}
