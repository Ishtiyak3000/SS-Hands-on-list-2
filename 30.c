/*
 ============================================================================================
  Name: 30.c
  Author: Ishtiyak Ahmad Khan
  Date : 20 SEPT 2024
  Description: Write a program to create a shared memory.
  a. write some data to the shared memory
  b. attach with O_RDONLY and check whether you are able to overwrite.
  c. detach the shared memory
  d. remove the shared memory
  ============================================================================================
*/
#include <sys/types.h> 
#include <sys/ipc.h>  
#include <sys/shm.h>   
#include <unistd.h>   
#include <stdio.h>     

void main()
{
    key_t shared_memory_key;        
    int shared_memory_id;   
    ssize_t lengthmessage = 20; 
    char *ptr, *read_only_ptr;
    shared_memory_key = ftok(".", 1);
    shared_memory_id = shmget(shared_memory_key, lengthmessage, IPC_CREAT | 0700);



    // a-write some data to the shared memory
    ptr = shmat(shared_memory_id, (void *)0, 0);
    printf("Press enter to write to the shared memory!\n");
    getchar();
    sprintf(ptr, "Ishtiyak");
    printf("Press enter to read from the shared memory!\n");
    getchar();
    printf("Data read from shared memory: %s\n", ptr);

    

    // b. attach with O_RDONLY and check whether you are able to overwrite.

    read_only_ptr = shmat(shared_memory_id, (void *)0, SHM_RDONLY);
    printf("Press enter to write to the shared memory!\n");
    getchar();
    sprintf(read_only_ptr, "Bengaluru"); 
    printf("Press enter to read from the shared memory!\n");
    getchar();
    printf("Data from shared memory: %s\n", read_only_ptr); // Reading from the shared memory

 

    //c. detach the shared memory
    shmdt(ptr); 
    shmdt(read_only_ptr); 



    //d. remove the shared memory
    shmctl(shared_memory_id, IPC_RMID, NULL);
    
}
