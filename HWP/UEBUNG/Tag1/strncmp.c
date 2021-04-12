/* strncmp.c */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	char str1[] = "HALLO";
	char str2[] = "HELLO";
	size_t len = strlen(str1);
	
	for(int i = len; i > 0; i--) {
		if(strncmp(str1, str2, i) != 0) 
			printf("Die ersten %d Zeichen der Strings sind nicht gleich\n", i);
		else {
			printf("Ab Zeichen %d sind beide Strings gleich\n", i);
			break;
		}
	}
	return EXIT_SUCCESS;
}
