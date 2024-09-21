/*
 ============================================================================================
  Name: 8g.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:Write a separate program using signal system call to catch the following signals
  g. SIGPROF (use setitimer system call)
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void message(int s) {
    printf("Profiling Timer Expired\n");
    exit(1);
}
int main() {
    signal(SIGPROF, message);                       
    struct itimerval timer = { {0}, {5, 0} };
    setitimer(ITIMER_PROF, &timer, NULL);  
    while(1);
    return 0;
}

