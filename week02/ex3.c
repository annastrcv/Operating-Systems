#include<stdio.h>

int main(int argc, char **argv){
    
    int n;
    sscanf(argv[1],"%d",&n);
    //scanf("%d", &n);
    int x,y;
    for (y= 1; y <= n; y++)
    {
        for (x= 0; x < n-y; x++)
            putchar(' ');
        for (x= 0; x < 2*y-1; x++)
            putchar('*');
        putchar('\n');
    }
    return 0;   
    
}
