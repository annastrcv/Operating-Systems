#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void handler_sigkill(int signal)
{
   printf("I'm intercepting sigkill\n");
   exit(0);
}
void handler_sigstop(int signal)
{
   printf("I'm intercepting sigstop\n");
   exit(0);
}
void handler_sigusr1(int signal)
{
   printf("I'm intercepting sigusr1\n");
   exit(0);
}

int main()
{
    signal(SIGKILL,handler_sigkill);
    signal(SIGSTOP,handler_sigstop);
    signal(SIGUSR1,handler_sigusr1);
    while(1){
        sleep(1);
    }
    return 0;
}
//output:
//[1] 2147
//kill -SIGUSR1 2147
//I'm intercepting sigusr1
//[1]  + done       ./a.out