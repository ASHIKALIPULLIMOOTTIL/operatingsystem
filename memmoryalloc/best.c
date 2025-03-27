#include<stdio.h>
#define MAX 25

int main()
{
    int nb, np, b[MAX], p[MAX], frag[MAX], i, j, temp, lowest;
    int bf[MAX] = {0}, ff[MAX] = {0}; 

    
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    
    printf("Enter the size of the blocks:-\n");
    for(i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &np);
    
    printf("Enter the size of the processes:-\n");
    for(i = 0; i < np; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i]);
    }

  
    for(i = 0; i < np; i++) {
        lowest = 10000;
        ff[i] = -1; 

        for(j = 0; j < nb; j++) {
            if(bf[j] == 0) { 
                temp = b[j] - p[i];
                if(temp >= 0 && temp < lowest) { 
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }

        if(ff[i] != -1) {
            frag[i] = lowest;
            bf[ff[i]] = 1; 
        } else {
            frag[i] = -1;
        }
    }

   
    printf("\nProcess No\tProcess Size\tBlock No\tBlock Size\tFragmentation\n");
    for(i = 0; i < np; i++) {
        if(ff[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, p[i], ff[i]+1, b[ff[i]], frag[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, p[i]);
    }

    return 0;
}

