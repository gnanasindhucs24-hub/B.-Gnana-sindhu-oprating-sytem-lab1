#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];


    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", p[i].id);
        scanf("%d", &p[i].burstTime);
        printf("Enter Priority for Process %d: ", p[i].id);
        scanf("%d", &p[i].priority);
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }


    p[0].waitingTime = 0;
    p[0].turnaroundTime = p[0].burstTime;

    for (int i = 1; i < n; i++) {
        p[i].waitingTime = p[i - 1].waitingTime + p[i - 1].burstTime;
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].id, p[i].burstTime, p[i].priority,
               p[i].waitingTime, p[i].turnaroundTime);
    }


    float avgWT = 0, avgTAT = 0;
    for (int i = 0; i < n; i++) {
        avgWT += p[i].waitingTime;
        avgTAT += p[i].turnaroundTime;
    }
    avgWT /= n;
    avgTAT /= n;

    printf("\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);

    return 0;
}


