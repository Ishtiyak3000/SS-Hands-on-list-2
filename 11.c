/*
 ============================================================================================
  Name: 11.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a program to ignore a SIGINT signal then reset the default action of the 
  SIGINT signal -use sigaction system call.
  ============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void message(int signo, siginfo_t *info, void *context) {
    printf("\nSIGINT ignored\n");
}
int main() {
    struct sigaction s,t;
    s.sa_sigaction = message;
    s.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &s, NULL);   
    printf("\nPress CTRL+C to see ignorance of the signal\n");
    sleep(5);                          
     t.sa_sigaction = SIG_DFL;
     t.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &t, NULL);           
    printf("SIGINT reset to default.Now if you press CTRL+C it will terminate\n");
    while(1);                           
    return 0;
}