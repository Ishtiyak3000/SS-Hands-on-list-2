/*
 ============================================================================================
  Name: 19.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Create a FIFO file by
  a. mknod command
  b. mkfifo command
  c. use strace command to find out, which command (mknod or mkfifo) is better.
  d. mknod system call
  e. mkfifo library function 
  ============================================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    system("mknod fifo_mknod p");
    system("mkfifo fifo_mkfifo");
    system("strace mknod fifo_mknod_strace p");
    system("strace mkfifo fifo_mkfifo_strace");
    mknod("fifo_mknod_syscall", S_IFIFO | 0666, 0);
    mkfifo("fifo_mkfifo_syscall", 0666);

    return 0;
}
