#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
    int pid = fork();
    if(pid){ //parent
        sleep(10);
        kill(pid, SIGTERM);
    }
    else{
        while(1){
            printf("I'm alive\n");
            sleep(1);
        }
    }
    return 0; 
}
//terminates after 10 sec of work
