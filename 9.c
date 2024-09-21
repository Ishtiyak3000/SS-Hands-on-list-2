/*
 ============================================================================================
  Name: 9.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a program to ignore a SIGINT signal then reset the default action of the 
  SIGINT signal - Use signal system call.
  ============================================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void message(int s) {
    printf("\nSIGINT ignored\n");
}
int main() {
    signal(SIGINT, message);   
    printf("\nPress CTRL+C to see ignorance of the signal");
    sleep(5);                          
    signal(SIGINT, SIG_DFL);            
    printf("SIGINT reset to default.Now if you press CTRL+C it will terminate\n");
    while(1);                           
    return 0;
}
