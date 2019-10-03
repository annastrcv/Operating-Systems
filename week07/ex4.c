#include <stdio.h>
#include <stdlib.h>

void *my_realloc(void * ptr, size_t size, size_t old_size ){
   if (ptr == NULL)
      return malloc(size);
   if (size == 0){
      free(ptr);
      return 0;
   }
   void* new_ptr;
   new_ptr = malloc(size);
   size_t min_size = size > old_size ? old_size : size;
   for(int i = 0; i < min_size; ++i)
   {
      ((int*)new_ptr)[i] = ((int*)ptr)[i];
   }
   return new_ptr;
}
int main()
{
   printf("Enter original array size:");
	int n1 = 0;
	scanf("%d", &n1);

	int* a1 = my_realloc(NULL, n1 * sizeof(int), 0);
	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;
		printf("%d ", a1[i]);
	}

	printf("\nEnter new array size: ");
	int n2 = 0;
	scanf("%d", &n2);

	a1 = my_realloc(a1,n2 * sizeof(int), n1* sizeof(int));  

    if(n2 > n1){
        for(i=n1; i<n2; i++)
		a1[i] = 0;
    }

	for(i = 0; i < n2; i++){
		printf("%d ", a1[i]);
	}
	printf("\n");

   a1 = my_realloc(a1 ,0 ,0);
	
   return 0;
}
