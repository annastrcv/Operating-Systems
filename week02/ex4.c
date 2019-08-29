#include <stdio.h> 
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}
int main() 
{ 
    int x, y;
    scanf("%d %d", &x, &y); 
    printf("x = %d, y = %d\n", x, y); 
    swap(&x, &y); 
    printf("x = %d, y = %d", x, y); 
    return 0;
} 
