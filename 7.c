/*
 ============================================================================================
  Name: 7.c
  Author: Ishtiyak Ahmad Khan
  Date : 11 SEPT 2024
  Description: Write a simple program to print created thread ids. 
  ============================================================================================
*/
#include <pthread.h>
#include <stdio.h>
void* message(void* arg) {
    printf("Thread ID: %ld\n", pthread_self());
    return NULL;
}
int main() {
    pthread_t threads[3];
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, message, NULL);
        pthread_join(threads[i], NULL);
    }
    return 0;
}

/*
output:
Thread ID: 125130055354048
Thread ID: 125130044868288
Thread ID: 125130034382528
*/