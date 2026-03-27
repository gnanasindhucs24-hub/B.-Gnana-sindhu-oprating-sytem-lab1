#include <stdio.h>
int main(){
    int i,n;
    int sys_bt[20],user_bt[20];
    int sys_wt[20],user_wt[20];
    int sys_n,user_n;
    int sys_tat[20],user_tat[20];
    printf("enter no of process ");
    scanf("%d",&sys_n);
    for(int i=0;i<sys_n;i++){
        printf("ënter the burst time of process %d:",i+1);
        scanf("%d",&sys_bt[i]);


    }
    printf("Enter no of process");
    scanf("%d",&user_n);
    for(i=0;i<user_n;i++){
        printf("Enter the burst time of user process %d",i+1);
        scanf("%d",&user_bt[i]);
    }
    sys_wt[0]=0;
    for(i=1;i<sys_n;i++)
        sys_wt[i]=sys_wt[i-1]+sys_bt[i-1];
    for(i=0;i<sys_n;i++)
        sys_tat[i]=sys_wt[i]+sys_bt[i];
    user_wt[0]=sys_wt[sys_n-1]+sys_bt[sys_n-1];
    for(i=1;i<user_n;i++)
        user_wt[i]=user_wt[i-1]+user_bt[i-1];
    for(i=0;i<user_n;i++)
        user_tat[i]=user_wt[i]+user_bt[i];
    printf("\nSystem process:\n");
    printf("process\tBursttime\twaitingtime\tturnaroundtime\n");
    for(i=0;i<sys_n;i++)
        printf("S%d\t%d\t\t%d\t\t%d\n",i+1,sys_bt[i],sys_wt[i],sys_tat[i]);
    printf("\nuser process:\n");
    printf("process\tBursttime\twaitingtime\tturnarouindtime\n");
    for(i=0;i<user_n;i++)
        printf("Ü%d\t%d\t\t%d\t\t%d\n",i+1,user_bt[i],user_wt[i],user_tat[i]);
    return 0;
}
