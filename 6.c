/*
 ============================================================================================
  Name: 6.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a simple program to create three threads. 
  ============================================================================================
*/
#include <pthread.h>
#include <stdio.h>

void* thread_func(void* arg) {
    printf("Thread %ld created\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t threads[3];
    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*)i);
        pthread_join(threads[i], NULL);
    }
    return 0;
}
/*
output:
Thread 0 created
Thread 1 created
Thread 2 created
*/