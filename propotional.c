#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int n,i;
    int tickets[10],totalTickets=0;
    int lottery,winner;
    printf("enter no of processs");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
       printf("Enter number of tickets for Process P%d: ", i+1);
       scanf("%d", &tickets[i]);
       totalTickets += tickets[i];
    }
       srand(time(0));
       printf("\nTotal Tickets = %d\n", totalTickets);
       lottery = rand() % totalTickets + 1;
       printf("Winning Ticket Number: %d\n", lottery);
       int sum = 0;
       for(i = 0; i < n; i++) {
          sum += tickets[i];
          if(lottery <= sum) {
             winner = i + 1;
               break;
          }
       }
               printf("Process P%d wins the lottery and gets the CPU.\n", winner);
               return 0;


}




