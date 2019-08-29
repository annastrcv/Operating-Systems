#include <stdio.h>
int main(){
    int a;
    float b;
    double c;
    a = __INT_MAX__;
    b = __FLT_MAX__;
    c = __DBL_MAX__;
    printf("%lu, %lu, %lu\n", sizeof(a), sizeof(b),sizeof(c));
    return 0;
}