/*
 ============================================================================================
  Name: 1c.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a separate program (for each time domain) to set a interval timer in 10sec and
  10micro second
  c. ITIMER_PROF 
  ============================================================================================
*/
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void signalhandler(int sig_no) {
    printf("professional-Timer Expired\n");
}
int main() {
    struct itimerval timer = {{10,10}, {10, 10}};
    signal(SIGPROF, signalhandler);
    setitimer(ITIMER_PROF, &timer, NULL); 
    while (1);
    return 0;
}

