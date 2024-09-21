/*
 ============================================================================================
  Name: 17c.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a program to execute ls -l | wc.
  c. use fcntl
  ============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd); 
    if (fork() == 0) { 
        close(fd[0]); 
        close(1); 
        fcntl(fd[1], F_DUPFD, STDOUT_FILENO);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
    } else { 
        sleep(1);
        close(fd[1]);
        close(0);
        fcntl(fd[0], F_DUPFD, STDIN_FILENO); 
        close(fd[0]);
        execlp("wc", "wc", NULL);
    }
    return 0;
}
