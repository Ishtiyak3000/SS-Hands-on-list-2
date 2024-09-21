/*
 ============================================================================================
  Name: 24.c
  Author: Ishtiyak Ahmad Khan
  Date : 12 SEPT 2024
  Description: Write a program to create a message queue and print the key and message queue id.
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

int main(){
    key_t key =12;
    int msgq_id = msgget(key, 0666 | IPC_CREAT);
    printf("Message Queue Key: %d\n",key);
    printf("Message Queue ID: %d\n",msgq_id);
    return 0;
}
/*
output:
Message Queue Key: 12
Message Queue ID: 6
*/