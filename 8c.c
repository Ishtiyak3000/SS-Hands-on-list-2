/*
 ============================================================================================
  Name: 8c.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:Write a separate program using signal system call to catch the following signals
  c.SIGFPE
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void message(int s) {
    printf("Caught floating point exception\n");
    exit(1);
}
int main() {
    signal(SIGFPE, message);                       
    int a=62/0;
    return 0;
}
