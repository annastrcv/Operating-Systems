#include <stdio.h>

int main() {
    char **s;   //pointer to pointer to char
    char foo[] = "Hello World"; //array of chars
    char *ptr = &foo;
    s = &ptr;
    //*s = foo;
    printf("s is %s\n", *s); // *s - char pointer
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    return(0);
}