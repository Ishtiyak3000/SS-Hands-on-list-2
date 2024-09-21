/*
  Name: 2.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  ============================================================================================
  Description: Write a program to print the system resource limits. Use getrlimit system call.  
  ============================================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
int main() {
    struct rlimit resource_limits;
    getrlimit(RLIMIT_NOFILE, &resource_limits); 
    printf("Max number of open files: %ld\n",resource_limits.rlim_max);
    return 0;
}
/*
output:Max number of open files: 1048576
*/