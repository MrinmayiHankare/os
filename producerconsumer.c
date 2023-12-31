#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_SIZE 5
#define MAX_ITEMS 5

int buffer[BUF_SIZE];
int in = 0, out = 0;
int produced_items = 0;
int consumed_items = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg) 
{
    int item = 1;
    while (produced_items < MAX_ITEMS) 
    {
        sleep(1);
        sem_wait(&empty);

        pthread_mutex_lock(&mutex);

        buffer[in] = item;

        printf("\nProduced item %d at position %d", item, in);
        in = (in + 1) % BUF_SIZE;

        pthread_mutex_unlock(&mutex);

        sem_post(&full);
        item++;
        produced_items++;
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    while (consumed_items < MAX_ITEMS) 
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        printf("\nConsumed item %d at position %d", item, out);
        out = (out + 1) % BUF_SIZE;

        pthread_mutex_unlock(&mutex);

        sem_post(&empty);
        item++;
        consumed_items++;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t consumer_thread, producer_thread;
    sem_init(&empty, 0, BUF_SIZE);
    sem_init(&full, 0, 0);

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);

    pthread_join(consumer_thread, NULL);
    pthread_join(producer_thread, NULL);

    return 0;
}
/*
output:
mayuri@mayuri-VirtualBox:~$ gcc ProducerConsumer.c
mayuri@mayuri-VirtualBox:~$ ./a.out

Produced item 1 at position 0
Consumed item 1 at position 0
Produced item 2 at position 1
Consumed item 2 at position 1
Produced item 3 at position 2
Consumed item 3 at position 2
Produced item 4 at position 3
Consumed item 4 at position 3
Produced item 5 at position 4
Consumed item 5 at position 4
*/

