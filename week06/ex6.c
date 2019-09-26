#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
    int pid1, pid2;
    int fd[2];
    pipe(fd);
    if(pid1 = fork()){ 
        if(pid2 = fork())//parent
        {
            printf("Parent's executing\n");
            int status;
            write(fd[1],&pid2,sizeof(pid2));
            printf("Parent's waiting for the 2nd child to change its state\n");
            waitpid(pid2, &status, 0);
            printf("Child2 changed its state\n");
        }
        else{//child2
            printf("Child2 is executing\n");
            while(1){
                sleep(1);
                printf("I'm still alive\n");
            }
        }
    }
    else{//child1
        printf("Child1 is executing\n");
        int id;
        read(fd[0],&id,sizeof(int));
        sleep(2);
        printf("Child1 is gonna kill child2\n");
        kill(id,SIGSTOP);
        kill(id, SIGTERM);
    }
    return 0; 
}

