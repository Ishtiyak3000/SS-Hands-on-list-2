/*
 ============================================================================================
  Name: 16.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:Write a program to send and receive data from parent to child vice versa. 
  Use two way communication.
  ============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
int main(){
    int parentTchild[2];
    int childTparent[2]; 
    char buffer[1024];
    pipe(parentTchild);
    pipe(childTparent);
    int pid = fork();
    if(pid == 0){
        sleep(1);
        close(parentTchild[1]);
        int bytesdata = read(parentTchild[0],buffer,sizeof(buffer));
        buffer[bytesdata] = '\0';
        printf("Message Sent by Parent: %s\n",buffer);
        close(parentTchild[0]);
        close(childTparent[0]);
        char* child_message = "Hi! I am the Child process\n";
        write(childTparent[1],child_message,strlen(child_message));
        close(childTparent[1]);

    }
    else{
        close(parentTchild[0]);
        char* parent_message = "Hi! I am the Parent process\n";
        write(parentTchild[1],parent_message,strlen(parent_message));
        close(parentTchild[1]);   
        sleep(3);
        close(childTparent[1]);
        int bytesdata = read(childTparent[0],buffer,sizeof(buffer));
        buffer[bytesdata] = '\0';
        printf("Message Sent by Child: %s\n",buffer);
        close(childTparent[0]);
    }

}