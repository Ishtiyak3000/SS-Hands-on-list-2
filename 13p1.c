/*
 ============================================================================================
  Name: 13p1.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description:Write two programs: first program is waiting to catch SIGSTOP signal, the second program
  will send the signal (using kill system call). Find out whether the first program is able to catch
  the signal or not.
  ============================================================================================
*/
//This is program 1 which is waiting to catch the SIGSTOP signal
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void message(int signo){
    printf("SIGSTOP signal recived\n");
    exit(1);
}

int main(){
    signal(SIGSTOP,message);
    while(1); 
}