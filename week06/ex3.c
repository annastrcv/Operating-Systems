#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void handler_sigint(int signal)
{
   printf("%d", 111);
   exit(0);
}

int main()
{
    signal(SIGINT,handler_sigint);
    while(1){
        sleep(1);
    }
    return 0;
}