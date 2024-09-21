/*
 ============================================================================================
  Name: 32.c
  Author: Ishtiyak Ahmad Khan
  Date : 20 SEPT 2024
  Description: Write a program to implement semaphore to protect any critical section.
  a. rewrite the ticket number creation program using semaphore
  b. protect shared memory from concurrent write access
  c. protect multiple pseudo resources ( may be two) using counting semaphore
  d. remove the created semaphore 
  ============================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

#define NUM_THREADS 5
#define NUM_RESOURCES 3

sem_t sem_ticket;
sem_t sem_shared_memory;
sem_t sem_resources;

int ticket_number = 0;
int *shared_memory;

void* create_ticket(void* arg) {
    sem_wait(&sem_ticket);
    printf("Thread %ld is creating ticket number: %d\n", (long)pthread_self(), ++ticket_number);
    sleep(1);
    sem_post(&sem_ticket);
    return NULL;
}

void* write_shared_memory(void* arg) {
    sem_wait(&sem_shared_memory);
    *shared_memory = 100 + (long)pthread_self();
    printf("Thread %ld wrote to shared memory: %d\n", (long)pthread_self(), *shared_memory);
    sleep(1);
    sem_post(&sem_shared_memory);
    return NULL;
}

void* access_resource(void* arg) {
    sem_wait(&sem_resources);
    printf("Thread %ld is accessing a resource\n", (long)pthread_self());
    sleep(2);
    sem_post(&sem_resources);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    key_t key = 1234;
    int shmid;

    sem_init(&sem_ticket, 0, 1);
    sem_init(&sem_shared_memory, 0, 1);
    sem_init(&sem_resources, 0, NUM_RESOURCES);

    shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    shared_memory = (int*)shmat(shmid, NULL, 0);
    if (shared_memory == (void*)-1) {
        perror("shmat failed");
        exit(1);
    }

    printf("\n--- Ticket Creation ---\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, create_ticket, NULL);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n--- Shared Memory Write ---\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, write_shared_memory, NULL);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n--- Accessing Resources ---\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, access_resource, NULL);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    shmdt(shared_memory);
    shmctl(shmid, IPC_RMID, NULL);

    sem_destroy(&sem_ticket);
    sem_destroy(&sem_shared_memory);
    sem_destroy(&sem_resources);

    printf("\nAll semaphores and shared memory have been cleaned up.\n");

    return 0;
}
/*
output:
--- Ticket Creation ---
Thread 137998154860224 is creating ticket number: 1
Thread 137998144374464 is creating ticket number: 2
Thread 137998165345984 is creating ticket number: 3
Thread 137998133888704 is creating ticket number: 4
Thread 137998123402944 is creating ticket number: 5

--- Shared Memory Write ---
Thread 137998123402944 wrote to shared memory: 824182564
Thread 137998144374464 wrote to shared memory: 845154084
Thread 137998154860224 wrote to shared memory: 855639844
Thread 137998133888704 wrote to shared memory: 834668324
Thread 137998165345984 wrote to shared memory: 866125604

--- Accessing Resources ---
Thread 137998165345984 is accessing a resource
Thread 137998154860224 is accessing a resource
Thread 137998144374464 is accessing a resource
Thread 137998123402944 is accessing a resource
Thread 137998133888704 is accessing a resource

All semaphores and shared memory have been cleaned up.
*/