/*
 ============================================================================================
  Name: 10b.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:10. Write a separate program using sigaction system call to catch the following 
  signals.
  b. SIGINT
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void signalHandler(int signo, siginfo_t *info, void *context){
    printf("SIGINT received\n");
    exit(1);
}
int main(){
    struct sigaction s;
    s.sa_sigaction = signalHandler;
    s.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &s, NULL);
    printf("Press Ctrl + C  to generate interrupt\n");
    while(1);
    return 0;
}

