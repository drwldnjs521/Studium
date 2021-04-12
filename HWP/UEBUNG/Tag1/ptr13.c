/* ptr13.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 250

char *eingabe(char *str) {
	char input[MAX];
	
	printf("Bitte \"%s \" eingeben.\n", str);
	fgets(input, MAX, stdin);
	return strtok(input, "\n");
}

int main(void) {
	char *ptr;
	
	ptr = eingabe("Vorname");
	printf("Hello, %s \n", ptr);
	ptr = eingabe("Nachname");
	printf("%s interessanter Name.\n", ptr);
	
	return EXIT_SUCCESS;
}
