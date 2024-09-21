/*
 ============================================================================================
  Name: 28.c
  Author: Ishtiyak Ahmad Khan
  Date : 20 SEPT 2024
  Description: Write a program to change the exiting message queue permission.
  (use msqid_ds structure)
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

int main(){
   struct msqid_ds info;
    key_t key = ftok("message queue",987);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    msgctl(msgid, IPC_STAT, &info);
    printf("Current permissions %o\n",info.msg_perm.mode);
    info.msg_perm.mode = 0644;
    msgctl(msgid, IPC_SET, &info);
    msgctl(msgid, IPC_STAT, &info);
    printf("New permissions %o\n",info.msg_perm.mode);
    msgctl(msgid, IPC_RMID, NULL);
    return 0;

}