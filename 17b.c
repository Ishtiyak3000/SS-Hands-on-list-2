/*
 ============================================================================================
  Name: 17b.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a program to execute ls -l | wc.
  b. use dup2
  ============================================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd); 

    if (fork() == 0) { 
        close(fd[0]);   
        dup2(fd[1], STDOUT_FILENO); 
        close(fd[1]);   
        execlp("ls", "ls", "-l", NULL); 
    } else { 
        sleep(1);
        close(fd[1]);   
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execlp("wc", "wc", NULL); 
    }
    return 0;
}
