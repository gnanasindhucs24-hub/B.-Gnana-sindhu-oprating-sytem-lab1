#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_ITEMS 5
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];

int in = 0;
int out = 0;

sem_t mutex;
sem_t full;
sem_t empty;

int produced_count = 0;
int consumed_count = 0;

void *producer(void *arg)
{
    sem_wait(&empty);
    sem_wait(&mutex);

    buffer[in] = produced_count + 1;

    printf("Producer produced item %d\n", buffer[in]);

    in = (in + 1) % BUFFER_SIZE;

    produced_count++;

    sem_post(&mutex);
    sem_post(&full);

    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    sem_wait(&full);
    sem_wait(&mutex);

    int item = buffer[out];

    printf("Consumer consumed item %d\n", item);

    buffer[out] = 0;

    out = (out + 1) % BUFFER_SIZE;

    consumed_count++;

    sem_post(&mutex);
    sem_post(&empty);

    pthread_exit(NULL);
}

int main()
{
    pthread_t prod_thread, cons_thread;

    int choice;

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);

    while (1)
    {
        printf("\n1. Producer\n2. Consumer\n3. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            if (produced_count - consumed_count < BUFFER_SIZE)
            {
                pthread_create(&prod_thread, NULL, producer, NULL);
                pthread_join(prod_thread, NULL);
            }
            else
            {
                printf("Buffer is full\n");
            }

            break;

        case 2:

            if (consumed_count < produced_count)
            {
                pthread_create(&cons_thread, NULL, consumer, NULL);
                pthread_join(cons_thread, NULL);
            }
            else
            {
                printf("Buffer is empty\n");
            }

            break;

        case 3:

            sem_destroy(&mutex);
            sem_destroy(&full);
            sem_destroy(&empty);

            return 0;

        default:

            printf("Invalid choice\n");
        }
    }

    return 0;
}
