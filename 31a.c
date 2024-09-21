/*
 ============================================================================================
  Name: 31a.c
  Author: Ishtiyak Ahmad Khan
  Date : 20 SEPT 2024
  Description: Write a program to create a binary_semaphore and initialize value to the binary_semaphore.
  a. create a binary binary_semaphore
  ============================================================================================
*/
#include <stdio.h>
#include <semaphore.h>
int main() {
    sem_t binary_semaphore;
    sem_init(&binary_semaphore, 0, 1);
    printf("Binary binary_semaphore created and initialized with 1.\n");
    sem_destroy(&binary_semaphore);
    printf("Binary binary_semaphore destroyed.\n");

    return 0;
}
