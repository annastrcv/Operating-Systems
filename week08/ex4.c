#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
int main ()
{
   for(int i = 0; i < 10; ++i){
      void* temp = malloc(10*1024*1024);
      memset(temp, 0, 10*1024*1024);
      struct rusage info;
      getrusage(RUSAGE_SELF,&info);
      printf("%ld\n",info.ru_maxrss);
      sleep(1);
   }
   return 0;
}