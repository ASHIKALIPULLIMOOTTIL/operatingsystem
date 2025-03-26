// C Program to implement First-Fit Algorithm
#include <stdio.h>

void main()
{
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10];

    for (int i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }

    printf("Enter number of blocks: ");
    scanf("%d", &bno);

    printf("\nEnter size of each block: ");
    for (int i = 0; i < bno; i++)
    {
        scanf("%d", &bsize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &pno);

    printf("\nEnter size of each process: ");
    for (int i = 0; i < pno; i++)
    {
        scanf("%d", &psize[i]);
    }

    // First Fit Allocation
    for (int i = 0; i < pno; i++)
    {
        for (int j = 0; j < bno; j++)
        {
            if (bsize[j] >= psize[i] && flags[j] == 0)
            {
                // Allocate block j to p[i] process
                allocation[i] = j;
                bsize[j] -= psize[i]; // Reduce the allocated block size
                flags[j] = 1; // Mark block as allocated
                break;
            }
        }
    }

    // Display allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < pno; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

