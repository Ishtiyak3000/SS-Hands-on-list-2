/*
 ============================================================================================
  Name: 27a.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a program to receive messages from the message queue.
  a. with 0 as a flag
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<unistd.h>

#define BUFFER_SIZE 100

struct msg{
    long msg_type;
    char msg_text[BUFFER_SIZE];
};

int main(){
    struct msg message;
    key_t key = ftok("message queue",1079);
    int q_id = msgget(key, 0666 | IPC_CREAT);
   
    for(int i=0;i<3;i++){
        message.msg_type = 1;       
        snprintf(message.msg_text,sizeof(message.msg_text),"Hi! I am Message %d",i+1);
        msgsnd(q_id, &message, sizeof(message.msg_text), 0);
        sleep(1);
    }
    message.msg_type = 1;
    strcpy(message.msg_text,"0");
    msgsnd(q_id, &message, sizeof(message.msg_text), 0);
    return 0;
}
