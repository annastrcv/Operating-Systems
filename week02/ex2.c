#include <stdio.h>
#include <string.h>
int main()
{
    // char* name;
    char name[255];
    char name_r[255];
    char c;
    int i = 0;
    int j=0;
    while((c= getchar())!='\n'){
        name[i] = c;
        ++i;
    }
    int size = strlen(name);
   
    for( i = size - 1; i >= 0; i--){
        name_r[j++] = name[i];
    }
    
    name_r[i] = '\0';
    printf("%s", name_r);
    return 0;
}
    