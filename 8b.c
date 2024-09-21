/*
 ============================================================================================
  Name: 8a.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:Write a separate program using signal system call to catch the following signals
  b.SIGINT
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void message(int sig) {
    printf("\nCaught interrupt signal\n");
    exit(1);
}
int main() {
    signal(SIGINT, message); 
    //waiting 5 seconds for the interrupt
    sleep(5);                      
    printf("press CTRL+C to send an interrupt\n");
    return 0;
}
