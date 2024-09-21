/*
 ============================================================================================
  Name: 10c.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:10. Write a separate program using sigaction system call to catch the following 
  signals.
  c. SIGFPE
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void signalHandler(int signo, siginfo_t *info, void *context){
    printf("floating point exception signal\n");
    exit(1);
}
int main(){
    struct sigaction s;
    s.sa_sigaction = signalHandler;
    s.sa_flags = SA_SIGINFO;
    sigaction(SIGFPE, &s, NULL);
    int a=62/0;
    while(1);
    return 0;
}
