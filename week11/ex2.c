#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main()
{
    char arr[1024];
    setvbuf(stdout,arr, _IOLBF,1024);
    char* str = "Hello";
    for(int i = 0; i < 5; i++){
        printf("%c", str[i]);
        sleep(1);
    }
    printf("\n");

    return 0;
}