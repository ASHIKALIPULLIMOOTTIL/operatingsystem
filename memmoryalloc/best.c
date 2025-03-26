// C Program to implement Best-Fit Algorithm
#include <stdio.h>

void main()
{
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of processes: ");
    scanf("%d", &np);

    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++)
    {
        printf("Block no. %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the processes:\n");
    for (i = 0; i < np; i++)
    {
        printf("Process no. %d: ", i + 1);
        scanf("%d", &p[i]);
    }

    // Best-Fit Allocation
    for (i = 0; i < np; i++)
    {
        temp = lowest;
        parray[i] = -1;
        
        for (j = 0; j < nb; j++)
        {
            if (barray[j] != 1)  // If block is not allocated
            {
                int fragment_size = b[j] - p[i];
                if (fragment_size >= 0 && fragment_size < temp)
                {
                    parray[i] = j;
                    temp = fragment_size;
                }
            }
        }

        if (parray[i] != -1)
        {
            fragment[i] = temp;
            barray[parray[i]] = 1; // Mark block as allocated
        }
    }

    // Display allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\tFragment\n");
    for (i = 0; i < np; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, p[i]);
        if (parray[i] != -1)
            printf("%d\t\t%d\n", parray[i] + 1, fragment[i]);
        else
            printf("Not Allocated\n");
    }
}

