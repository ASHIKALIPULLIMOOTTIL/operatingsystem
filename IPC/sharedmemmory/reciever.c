#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    void *shared_memory;
    int shmid;

    shmid = shmget((key_t)1122, 1024, 0666); // Get shared memory
    printf("Key of shared memory is %d\n", shmid);

    shared_memory = shmat(shmid, NULL, 0); // Process attached to shared memory
    printf("Process attached at %p\n", shared_memory);

    printf("Data read from shared memory is: %s\n", (char *)shared_memory);
    return 0;
}

