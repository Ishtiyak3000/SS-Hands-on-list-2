/*
 ============================================================================================
  Name: 8a.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:Write a separate program using signal system call to catch the following signals
  a.SIGSEGV
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void message(int sig) {
    printf("Caught segmentation fault\n");
    exit(1);
}
int main() {
    signal(SIGSEGV, message);                       
     int a[1]={100};
    int value=a[1000000000000];
    return 0;
}
