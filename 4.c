/*
  Name:-4.c
  Author:-Ishtiyak Ahmad Khan
  Date :- 11 SEPT 2024
  ============================================================================================
  Description. Write a program to measure how much time is taken to execute 100 getppid()
  system call. Use time stamp counter. 
  ============================================================================================
*/
#include <stdio.h>
#include <x86intrin.h>
#include <unistd.h>
int main() {
    int start, end;
    start = __rdtsc();
    for (int i = 0; i < 100; i++) {
        getppid();
    }
    end = __rdtsc();
    printf("Time taken to execute 100 getppid() calls: %d cycles\n", end - start);
    return 0;
}
/*Sample Output:
Time taken to execute 100 getppid() calls: 78738 cycles
*/