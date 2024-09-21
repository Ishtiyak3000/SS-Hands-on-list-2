/*
 ============================================================================================
  Name: 5.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a program to print the system limitation of
  a. maximum length of the arguments to the exec family of functions.
  b. maximum number of simultaneous process per user id.
  c. number of clock ticks (jiffy) per second.
  d. maximum number of open files
  e. size of a page
  f. total number of pages in the physical memory
  g. number of currently available pages in the physical memory. 
  ============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    sysinfo(&info);
    printf("Max length of arguments for exec: %ld\n", sysconf(_SC_ARG_MAX));
    printf("Max processes per user id: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("Max open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Page size: %ld bytes\n", sysconf(_SC_PAGESIZE)); 
    printf("Total number of pages: %lu\n", info.totalram / sysconf(_SC_PAGESIZE));
    printf("Available pages: %lu\n", info.freeram / sysconf(_SC_PAGESIZE));
    return 0;
}
/*
output:
Max length of arguments for exec: 2097152
Max processes per user id: 62755
Clock ticks per second: 100
Max open files: 1048576
Page size: 4096 bytes
Total number of pages: 4034125
Available pages: 2602226
*/