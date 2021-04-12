/* strings_verbinden.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void strings_verbinden(char *zusammen, char *string1, char *string2) {
	

	int i;
	size_t len = strlen(string1) + strlen(string2);
	
	for(i = 0; i < strlen(string1); i++) 
		*(zusammen + i) = *(string1 + i);
	for(i = 0; i < strlen(string2); i++) 
		*(zusammen + strlen(string1) + i) = *(string2 + i);
	
	
	*(zusammen + len) = '\0';
		
}
		
  
