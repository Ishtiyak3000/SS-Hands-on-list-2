/*
 ============================================================================================
  Name: 23.c
  Author: Ishtiyak Ahmad Khan
  Date : 12 SEPT 2024
  Description: Write a program to print the maximum number of files can be opened within a process
  and size of a pipe (circular buffer).
  ============================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <stdlib.h>

#define MAX_BUF 100

int main()
{
  struct rlimit limit;
  getrlimit(RLIMIT_NOFILE, &limit);
  printf("Maximum number of open files per process: %ld\n", limit.rlim_cur);
  int fd = open("/proc/sys/fs/pipe-max-size", O_RDONLY);
  char buffer[MAX_BUF];
  ssize_t bytes_read = read(fd, buffer, MAX_BUF);
  buffer[bytes_read] = '\0';
  printf("Maximum pipe size (circular buffer): %s bytes", buffer);
  close(fd);
  return 0;
}
/*
output:
Maximum number of open files per process: 1048576
Maximum pipe size (circular buffer): 1048576
*/