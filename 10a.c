/*
 ============================================================================================
  Name: 10a.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:10. Write a separate program using sigaction system call to catch the following 
  signals.
  a. SIGSEGV
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
void message(int signo, siginfo_t *info, void *context){
    printf("SIGSEGV received\n");
    exit(1);
}

int main(){

    struct sigaction s;
    s.sa_sigaction = message;
    s.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV,&s,NULL);
    int a[1]={5};
    int d=a[100000000000];
    return 0;
}
