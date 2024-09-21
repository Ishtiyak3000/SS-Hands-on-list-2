/*
 ============================================================================================
  Name: 31b.c
  Author: Ishtiyak Ahmad Khan
  Date : 20 SEPT 2024
  Description: Write a program to create a semaphore and initialize value to the semaphore.
  b. create a counting semaphore
  ============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int main() {
    sem_t counting_semaphore;
    sem_init(&counting_semaphore,0,2) ;
    printf("Counting semaphore created and initialized with value 2.\n");
    sem_destroy(&counting_semaphore);
    printf("Counting semaphore destroyed.\n");

    return 0;
}