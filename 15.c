/*
 ============================================================================================
  Name: 15.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a simple program to send some data from parent to the child process. 
  ============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    int pipefd[2];
    pipe(pipefd);
    char buffer[50];
    int pid = fork();
    if(pid == 0){
        close(pipefd[1]);
        int numBytes = read(pipefd[0], buffer, sizeof(buffer));
        buffer[numBytes] = '\0'; 
        printf("Data Sent by Parent: \n");
        printf("%s\n",buffer);
        close(pipefd[0]);

    }
    else{
        close(pipefd[0]);
        char* data = "Hi! I am the parent process";
        write(pipefd[1],data, strlen(data)+1);
        close(pipefd[1]);
        wait(NULL);
    }

    return 0;
}