/* ptr1.c */ 
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *p;
	int x = 5;
	
	p = &x;
	
	printf("Did Adresse von x ist %p \n", p);
	
	return EXIT_SUCCESS;
} 
