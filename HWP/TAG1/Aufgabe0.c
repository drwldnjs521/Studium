/* Aufgabe0 */ 
#include <stdio.h>
#include <stdlib.h>

/* (a) */
int even(int a) {
	if(a % 2) 
		return 0;
	else 
		return 1;
}

/* (b) */

int main(void) {
	
	int i;
	
	printf("Geben Sie eine Zahl ein: ");
	scanf("%d", &i);
	if(even(i))
		printf("Die Zahl ist gerade!\n");
	else 
		printf("Die Zahl ist nicht gerade!\n");
	
	return EXIT_SUCCESS;
}


