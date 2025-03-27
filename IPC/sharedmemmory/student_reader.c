#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

typedef struct {
    char name[50];
    int marks;
} Student;


int compare(const void *a, const void *b) {
    return ((Student *)b)->marks - ((Student *)a)->marks;
}

int main() {
    int shmid = shmget((key_t)1122, 0, 0666);
    if (shmid == -1) {
        perror("Shared memory access failed");
        exit(1);
    }

    void *shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("Shared memory attachment failed");
        exit(1);
    }

    int *num_students = (int *)shared_memory;
    int n = *num_students;

    Student *students = (Student *)(shared_memory + sizeof(int));

   
    qsort(students, n, sizeof(Student), compare);

    
    printf("\nRanked List of Students:\n");
    for (int i = 0; i < n; i++) {
        printf("Rank %d: %s - Marks: %d\n", i + 1, students[i].name, students[i].marks);
    }

    shmdt(shared_memory); 
    shmctl(shmid, IPC_RMID, NULL); 

    return 0;
}

