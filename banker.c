#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int main()
{
    int n, m;
    int Allocation[MAX][MAX], Max[MAX][MAX], Need[MAX][MAX];
    int Available[MAX], Work[MAX], SafeSeq[MAX];
    bool Finish[MAX] = {false};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resource types: ");
    scanf("%d",&m);

    printf("\nEnter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&Allocation[i][j]);

    printf("\nEnter Max Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&Max[i][j]);

    printf("\nEnter Available Vector:\n");
    for(int j=0;j<m;j++)
        scanf("%d",&Available[j]);

    /* Calculate Need Matrix */
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            Need[i][j]=Max[i][j]-Allocation[i][j];
        }
    }

    printf("\nNeed Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d ",Need[i][j]);
        printf("\n");
    }

    for(int j=0;j<m;j++)
        Work[j]=Available[j];

    int count=0;

    while(count<n)
    {
        bool found=false;

        for(int i=0;i<n;i++)
        {
            if(Finish[i]==false)
            {
                bool possible=true;

                for(int j=0;j<m;j++)
                {
                    if(Need[i][j]>Work[j])
                    {
                        possible=false;
                        break;
                    }
                }

                if(possible)
                {
                    for(int j=0;j<m;j++)
                        Work[j]+=Allocation[i][j];

                    SafeSeq[count]=i;
                    count++;

                    Finish[i]=true;
                    found=true;
                }
            }
        }

        if(found==false)
        {
            printf("\nSystem is NOT in Safe State\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state\n");

    printf("Safe Sequence: ");
    for(int i=0;i<n;i++)
        printf("P%d ",SafeSeq[i]);

    return 0;
}
