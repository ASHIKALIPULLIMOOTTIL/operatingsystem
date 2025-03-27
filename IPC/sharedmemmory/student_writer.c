#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

typedef struct {
    char name[50];
    int marks;
} Student;

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    int shmid = shmget((key_t)1122, sizeof(Student) * n + sizeof(int), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("Shared memory creation failed");
        exit(1);
    }

    void *shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("Shared memory attachment failed");
        exit(1);
    }

    int *num_students = (int *)shared_memory;
    *num_students = n; 

    Student *students = (Student *)(shared_memory + sizeof(int));

    
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    printf("Student details saved in shared memory.\n");

    shmdt(shared_memory); 
    return 0;
}

