/*
============================================================================================
  Name: 1b.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024 
  Description: Write a separate program (for each time domain) to set a interval timer in 10sec and
  10micro second
  b. ITIMER_VIRTUAL
  ============================================================================================
*/
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void signalhandler(int sig_no) {
    printf("virtual-Timer Expired\n");
}
int main() {
    struct itimerval timer = {{10,10}, {10, 10}};
    signal(SIGVTALRM, signalhandler);
    setitimer(ITIMER_VIRTUAL, &timer, NULL); 
    while (1);
    return 0;
}

