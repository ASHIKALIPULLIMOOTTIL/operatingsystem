#include<stdio.h>

int main() {
    int bno, pno, bs[20], ps[20], allocated[20] = {0}, i, j;

    
    printf("Enter number of Blocks: ");
    scanf("%d", &bno);
    for (i = 0; i < bno; i++) {
        printf("Enter the size of Block %d: ", i + 1);
        scanf("%d", &bs[i]);
    }

    
    printf("Enter number of Processes: ");
    scanf("%d", &pno);
    for (i = 0; i < pno; i++) {
        printf("Enter the size of Process %d: ", i + 1);
        scanf("%d", &ps[i]);
    }

   
    for (j = 0; j < pno; j++) {
        for (i = 0; i < bno; i++) {
            if (ps[j] <= bs[i] && allocated[i] == 0) {
                printf("Process %d (size %d) allocated to Block %d (size %d)\n", j + 1, ps[j], i + 1, bs[i]);
                allocated[i] = 1; 
                break;
            }
        }
        if (i == bno) {
            printf("Process %d (size %d) is not allocated\n", j + 1, ps[j]);
        }
    }

    return 0;
}

