#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    void *shared_memory;
    char buff[100];
    int shmid;

    shmid = shmget((key_t)1122, 1024, 0666 | IPC_CREAT); // Creates shared memory
    printf("Key of shared memory is %d\n", shmid);

    shared_memory = shmat(shmid, NULL, 0); // Process attached to shared memory
    printf("Process attached at %p\n", shared_memory);

    printf("Enter some data to write to shared memory\n");
    read(0, buff, 100); // Get input from user
    strcpy(shared_memory, buff); // Write data to shared memory

    printf("You wrote: %s\n", (char *)shared_memory);
    return 0;
}

