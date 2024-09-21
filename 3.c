/*
 ============================================================================================
  Name: 3.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a program to set (any one) system resource limit. Use setrlimit system call. 
  ============================================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
int main() {
    struct rlimit lim; 
    lim.rlim_cur = 1024;
    lim.rlim_max = 2048;
    setrlimit(RLIMIT_NOFILE, &lim);
    struct rlimit resource_limits;
    getrlimit(RLIMIT_NOFILE, &resource_limits); 
    printf("Max number of open files: %ld\n",resource_limits.rlim_max);
    return 0;
}
/*
output:Max number of open files: 2048
*/