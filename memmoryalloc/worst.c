// C Program to implement Worst-Fit Algorithm
#include <stdio.h>

void main()
{
    int bsize[20], psize[20]; 
    int all[20], m, n, i, j;

    printf("Enter the number of Blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each block:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &bsize[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &psize[i]);
        all[i] = -1; // Initialize allocation array
    }

    // Worst-Fit Allocation
    for (i = 0; i < n; i++)
    {
        int worstPlace = -1;
        for (j = 0; j < m; j++)
        {
            if (bsize[j] >= psize[i])
            {
                if (worstPlace == -1 || bsize[j] > bsize[worstPlace])
                {
                    worstPlace = j;
                }
            }
        }

        if (worstPlace != -1)
        {
            // Allocate process to the worst block found
            all[i] = worstPlace;
            bsize[worstPlace] -= psize[i]; // Reduce available block size
        }
    }

    // Display allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if (all[i] != -1)
            printf("%d\n", all[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

