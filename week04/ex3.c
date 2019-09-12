#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char* s;
    s = (char *)malloc(sizeof(char)*1024);
    scanf("%s", s);
    system(s);
    return 0;
}