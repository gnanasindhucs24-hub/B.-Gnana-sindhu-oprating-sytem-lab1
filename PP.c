#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int priority;
    int wt;
    int tat;
    int rt;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time, Burst Time, Priority for P%d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].rt = p[i].bt;
    }

    int completed = 0, time = 0;
    float totalWT = 0, totalTAT = 0;

    while (completed < n) {
        int idx = -1;
        int highest_priority = 9999;


        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].rt--;
            time++;
            if (p[idx].rt == 0) {
                completed++;
                int finish_time = time;
                p[idx].tat = finish_time - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                totalWT += p[idx].wt;
                totalTAT += p[idx].tat;
            }
        } else {
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);

    return 0;
}
