#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

struct thread_data
{
  int  thread_id;
  char *message;
};


void *PrintHello(void *threadarg)
{
   struct thread_data *my_data;   
   my_data = (struct thread_data *) threadarg;
   printf("Thread ID : %d ",my_data->thread_id);
   printf("Message : %s\n",my_data->message);
   pthread_exit(NULL);
}

int main ()
{
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc, i;

   for( i=0; i < NUM_THREADS; i++ )    
   {
       printf("main() : creating thread, %d\n",i);
       td[i].thread_id = i;
       td[i].message = "This is message";
       rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);
        if (rc){
            printf("Error:unable to create thread,%d\n", rc);
            exit(-1);    
      }    
      pthread_join(threads[i], NULL);
   }    
   pthread_exit(NULL);    
}