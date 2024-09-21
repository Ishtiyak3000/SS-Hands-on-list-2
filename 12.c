/*
 ============================================================================================
  Name: 12.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a program to create an orphan process. Use kill system call to send 
  SIGKILL signal to the parent process from the child process. 
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(){

    int id = fork();
    if(id == 0){
        sleep(5);
        int parent_pid = getppid();
        printf("Before becoming Orphan Parent Process id: %d\n",parent_pid);
        kill(parent_pid,SIGKILL);
        
        printf("Process has become Orphan\n");
        while(1);
        
    }
    else{
        printf("Waiting for a Signal from Child Process\n");
        sleep(10);
    }

    return 0;
}

