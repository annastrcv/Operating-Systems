#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int BUFFER[10];
int i = 0;
pthread_cond_t sync;

void *consumer(void* args)
{
    while(1)
    {
       if (i == 0){
        pthread_cond_wait(&sync, NULL);
        continue;
        }
        printf("%d\n", BUFFER[i]);
        i--;
        pthread_cond_signal(&sync);
    }
}
void *producer(void* args)
{
    time_t last = 0;
    int c = 1;
    while(1)
    {
   
    if (i == 10){
        pthread_cond_wait(&sync, NULL);
        continue;
    }
    if (time(NULL) - last < 60){
        last = time(NULL);
        printf("Element was added\n");
    }
    BUFFER[i] = c;
    i++;
    c++;
    }
}

int main()
{
    pthread_cond_init(&sync, NULL);

    pthread_t producer_t, consumer_t;

    pthread_create(&producer_t, NULL, producer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);
    return 0;
}