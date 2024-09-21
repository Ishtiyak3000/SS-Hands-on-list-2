/*
 ============================================================================================
  Name: 22.c
  Author: Ishtiyak Ahmad Khan
  Date : 12 SEPT 2024
  Description: Write a program to wait for data to be written into FIFO within 10 seconds, use select
  system call with FIFO.   
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <errno.h>

int main() {
    char *fifo_name = "my_fifo";
    mkfifo(fifo_name,0666);
    int fd = open(fifo_name, O_RDONLY | O_NONBLOCK);
    char message[100];
    fd_set read_fds;
    struct timeval timeout;

    while (1) {
        
        FD_ZERO(&read_fds);
        FD_SET(fd, &read_fds);
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        int ret = select(fd + 1, &read_fds, NULL, NULL, &timeout);
        if (ret == -1) {
            perror("select error");
            break;
        } else if (ret == 0) {
            printf("No data received within 10 seconds. Timing out...\n");
            break;
        } else {
            read(fd, message, sizeof(message));
            if (strlen(message) == 0) {
                break; 
            }
            printf("Received: %s\n", message); 
            exit(EXIT_SUCCESS);
        }
    }

  
    close(fd);
    unlink(fifo_name);
    return 0;
}
