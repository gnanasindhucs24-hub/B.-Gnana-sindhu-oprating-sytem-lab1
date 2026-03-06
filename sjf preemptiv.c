#include <stdio.h>
#include <limits.h>

int main() {
    int n,i,time=0,smallest,complete=0;
    int bt[20],rt[20],wt[20],tat[20],at[20];
    int finish;
    float total_wt=0,total_tat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter arrival time and burst time for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];   // remaining time
    }

    while(complete!=n){
        smallest=-1;
        int min=INT_MAX;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0 && rt[i]<min){
                min=rt[i];
                smallest=i;
            }
        }

        if(smallest==-1){
            time++;
            continue;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest]==0){
            complete++;
            finish=time;

            wt[smallest]=finish-bt[smallest]-at[smallest];
            if(wt[smallest]<0)
                wt[smallest]=0;

            tat[smallest]=bt[smallest]+wt[smallest];

            total_wt+=wt[smallest];
            total_tat+=tat[smallest];
        }
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",total_wt/n);
    printf("\nAverage Turnaround Time = %.2f",total_tat/n);

    return 0;
}
