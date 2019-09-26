#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
   int fd[2];
   pipe(fd);
   char s1[128] = "abc";
   char s2[128];
   if(fork())
        write(fd[1], s1, 128);
   else {
      read(fd[0], s2, 128);
      printf("%s",s2);
   }
   return 0;
}