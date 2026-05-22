#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int main()
{
    int n,m;
    int Allocation[MAX][MAX];
    int Request[MAX][MAX];
    int Available[MAX];
    int Work[MAX];

    bool Finish[MAX];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resource types: ");
    scanf("%d",&m);

    printf("\nEnter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&Allocation[i][j]);

    printf("\nEnter Request Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&Request[i][j]);

    printf("\nEnter Available Vector:\n");
    for(int j=0;j<m;j++)
        scanf("%d",&Available[j]);

    /* Step 1 */
    for(int j=0;j<m;j++)
        Work[j]=Available[j];

    for(int i=0;i<n;i++)
    {
        bool allocated=false;

        for(int j=0;j<m;j++)
        {
            if(Allocation[i][j]!=0)
            {
                allocated=true;
                break;
            }
        }

        if(allocated)
            Finish[i]=false;
        else
            Finish[i]=true;
    }

    /* Step 2 and 3 */
    while(1)
    {
        bool found=false;

        for(int i=0;i<n;i++)
        {
            if(Finish[i]==false)
            {
                bool possible=true;

                for(int j=0;j<m;j++)
                {
                    if(Request[i][j]>Work[j])
                    {
                        possible=false;
                        break;
                    }
                }

                if(possible)
                {
                    for(int j=0;j<m;j++)
                        Work[j]+=Allocation[i][j];

                    Finish[i]=true;

                    found=true;
                }
            }
        }

        if(found==false)
            break;
    }

    bool deadlock=false;

    printf("\nDeadlocked Processes: ");

    for(int i=0;i<n;i++)
    {
        if(Finish[i]==false)
        {
            printf("P%d ",i);
            deadlock=true;
        }
    }

    if(deadlock==false)
        printf("None");

    printf("\n");

    if(deadlock)
        printf("System is in DEADLOCK state");
    else
        printf("System is NOT in deadlock state");

    return 0;
}
