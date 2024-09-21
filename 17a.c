/*
 ============================================================================================
  Name: 17a.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a program to execute ls -l | wc.
  a. use dup
  ============================================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);
    if (fork() == 0) { 
        close(fd[0]);
        close(1);   
        dup(fd[1]);     
        close(fd[1]);   
        execlp("ls", "ls", "-l", NULL); 
    } else { 
        sleep(1);
        close(fd[1]); 
        close(0);  
        dup(fd[0]);     
        close(fd[0]);  
        execlp("wc", "wc", NULL); 
    }
    return 0;
}
