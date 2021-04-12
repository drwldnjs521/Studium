/* arr_ptr1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int elements[] = {1, 2, 3, 4, 5, 6, 7};
	int *ptr;
	int i;
	
	ptr = elements;
	
	printf("Der Wert, auf den *ptr zeigt, ist %d.\n", *ptr);
	printf("Durch *ptr+1 zeigt er jetzt auf %d.\n", *(ptr+1));
	printf("*(ptr+3)  = %d \n", *(ptr+3));
	printf("Jetzt alle zusammen: \n");
	for(i=0; i<(sizeof(elements)/sizeof(int)) ; i++) 
		printf("elements[%d] = %d\n", i, *(ptr+i));
	return EXIT_SUCCESS;
}
