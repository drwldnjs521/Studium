/* ptr8.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x = 5;
	int *ptr1, *ptr2;

	ptr1 = &x;
	ptr2 = ptr1;
	
	printf("ptr1 verweist auf %p\n", ptr1);
	printf("Wert in %p ist %d\n", ptr1, *ptr1);
	
	printf("ptr2 verweist auf %p\n", ptr2);
	printf("Wert in %p ist %d\n", ptr2, *ptr2);
	
	printf("Adresse von ptr1 : %p \n", &ptr1);
	printf("Adresse von ptr2 : %p \n", &ptr2);
	printf("Adresse von x : %p \n", &x);
	
	return EXIT_SUCCESS;
}
