/* strtok.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char string[] = "Hallo, mein name ist Jeewon Lee";
	
	int i = 1;
	char *ptr;
	
	ptr = strtok(string, ",\n ");
	while(ptr != NULL) {
		printf("% d. Wort: %s\n", i++, ptr);
		ptr = strtok(NULL, ",\n ");
		
	}
	return EXIT_SUCCESS;
}
