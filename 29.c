/*
 ============================================================================================
  Name: 29.c
  Author: Ishtiyak Ahmad Khan
  Date : 20 SEPT 2024
  Description: Write a program to remove the message queue
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

int main() {
    key_t key = ftok("msgqueue", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    printf("Message queue created with ID: %d\n", msgid);
    msgctl(msgid, IPC_RMID, NULL) ;
    return EXIT_SUCCESS;
}
