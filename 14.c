/*
 ============================================================================================
  Name: 14.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:Write a simple program to create a pipe, write to the pipe, read from pipe and 
  display on the monitor. 
  ============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int pipefd[2];
    pipe(pipefd);
    char buffer[50];
    int pid = fork();
    if(pid == 0){
        close(pipefd[0]);
        char* data = "Hi! I am your son";
        write(pipefd[1],data, strlen(data)+1);
        close(pipefd[1]);
    }
    else{
        close(pipefd[1]);
        sleep(5);
        int numBytes = read(pipefd[0], buffer, sizeof(buffer));
        buffer[numBytes] = '\0'; 
        printf("%s\n",buffer);
        close(pipefd[0]);
    }
    return 0;
}