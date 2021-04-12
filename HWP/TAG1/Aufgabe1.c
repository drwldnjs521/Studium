/* Aufgabe1.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX 12

int main(void) {
	double arr[MAX];
	double *ptr;
	
	ptr = arr;
	
	printf("Geben Sie 12 Messwerte ein.\n");
	for(int i = 0; i < MAX; i++) {
		printf("%d. Wert: ", i+1);
		scanf("%lf", (ptr+i));
	}
	
	printf("Die gegebene Werte:\n");
	for(int i = 0; i < MAX; i++) 
		printf("%d. Wert: %f\n", i+1, *(ptr+i));
		
	return EXIT_SUCCESS;
}
		
