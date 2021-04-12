/* Aufgabe2.c */
#include <stdio.h>
#include <stdlib.h>

void swap(int *ap, int *bp) {
	
	int tmp;
	
	tmp = *ap;
	*ap = *bp;
	*bp = tmp;
	
	
}
int main(void) {
	
	int a, b;
	
	printf("Geben Sie den Wert der Variable a ein:");
	scanf("%d", &a);
	printf("Geben Sie den Wert der Variable b ein:");
	scanf("%d", &b);
	
	printf("Vor swap: a = %d, b = %d\n", a, b);
	
	swap(&a,&b);
	
	printf("Nach swap: a = %d, b = %d\n", a, b);
	
	return EXIT_SUCCESS;
	
}
	
	
