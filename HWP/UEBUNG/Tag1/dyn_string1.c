/* dyn_string1.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF 255

int main(void) {
	size_t len;
	char *ptr;
	char puffer[BUF];
	
	printf("Ein dynamisches char Array für String.\n");
	printf("EINGABE MACHEN: ");
	fgets(puffer, BUF, stdin);
	
	ptr = malloc(strlen(puffer) + 1);
	if(ptr == NULL) {
		printf("Kein virtueller RAM mehr vorhanden.");
		return EXIT_FAILURE;
	}
	strcpy(ptr, puffer);
	printf("Weitere Eingabe oder Beenden mit \" END \"\n>");
	while(1) {
		fgets(puffer, BUF, stdin);
		
		if(strcmp(puffer, "end\n") == 0 || strcmp(puffer, "END\n") == 0) 
			break;
		
		len = strlen(ptr);
		ptr = realloc(ptr, strlen(puffer) + len + 1);
		if(NULL == ptr) {
			printf("Kein virtueller RAM mehr vorhanden");
			return EXIT_FAILURE;
		}
		
		strcat(ptr, puffer);
		
	}
	
	printf("Ihre Eingabe lautet:" );
	ptr = strtok(ptr, "\n");
	printf("%s", ptr);
	free(ptr);
	return EXIT_SUCCESS;
}

	
