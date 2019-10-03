#include <stdio.h>
#include <stdlib.h>

int main ()
{
   printf("Type in the size of an array: ");
   int n;   //size of an array
   scanf("%d", &n);
   int *array = malloc(n * sizeof(int));
   for(int i = 0; i < n; ++i){
      array[i] = i;
      printf("%d ", array[i]);
   }
   free(array);
   printf("\n");
   return 0;
}