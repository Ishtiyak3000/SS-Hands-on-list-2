/*
 ============================================================================================
  Name: 13p2.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:Write two programs: first program is waiting to catch SIGSTOP signal, the second program
  will send the signal (using kill system call). Find out whether the first program is able to catch
  the signal or not.
  ============================================================================================
*/
//This is program 2 which will send the SIGSTOP signal
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(){
    int pid;
    system("pgrep a.out");
    printf("Enter The above process id: ");
    scanf("%d",&pid);
    printf("\nSending SIGSTOP\n");
    kill(pid,SIGSTOP);
    printf("SIGSTOP SENT\n");
    return 0;   
}
