#include <stdio.h>

#define MAX 10

// First Fit
void firstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[MAX];

    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nFirst-Fit Allocation:\n");

    for (int i = 0; i < processes; i++)
    {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n",
                   i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n",
                   i + 1, processSize[i]);
    }
}

// Best Fit
void bestFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[MAX];

    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    for (int i = 0; i < processes; i++)
    {
        int best = -1;

        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (best == -1 || blockSize[j] < blockSize[best])
                    best = j;
            }
        }

        if (best != -1)
        {
            allocation[i] = best;
            blockSize[best] -= processSize[i];
        }
    }

    printf("\nBest-Fit Allocation:\n");

    for (int i = 0; i < processes; i++)
    {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n",
                   i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n",
                   i + 1, processSize[i]);
    }
}

// Worst Fit
void worstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[MAX];

    for (int i = 0; i < processes; i++)
        allocation[i] = -1;

    for (int i = 0; i < processes; i++)
    {
        int worst = -1;

        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worst == -1 || blockSize[j] > blockSize[worst])
                    worst = j;
            }
        }

        if (worst != -1)
        {
            allocation[i] = worst;
            blockSize[worst] -= processSize[i];
        }
    }

    printf("\nWorst-Fit Allocation:\n");

    for (int i = 0; i < processes; i++)
    {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n",
                   i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n",
                   i + 1, processSize[i]);
    }
}

int main()
{
    int blockSize[MAX], processSize[MAX];
    int originalBlockSize[MAX];
    int blocks, processes, choice;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blocks);

    printf("Enter size of each block:\n");

    for (int i = 0; i < blocks; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);

        originalBlockSize[i] = blockSize[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &processes);

    printf("Enter size of each process:\n");

    for (int i = 0; i < processes; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    printf("\nMemory Allocation Techniques:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter choice: ");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        firstFit(blockSize, blocks, processSize, processes);
        break;

    case 2:
        for (int i = 0; i < blocks; i++)
            blockSize[i] = originalBlockSize[i];

        bestFit(blockSize, blocks, processSize, processes);
        break;

    case 3:
        for (int i = 0; i < blocks; i++)
            blockSize[i] = originalBlockSize[i];

        worstFit(blockSize, blocks, processSize, processes);
        break;

    default:
        printf("Invalid choice.\n");
    }

    return 0;
}
