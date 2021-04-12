/* const_ptr.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void function(char *string) {
	char *ptr;
	
	ptr = string+5;
	*ptr = '-';
	
	printf("%s\n", string);
}

int main(void) {

	char str[] = "Hello World\n";
	
	function(str);
	
	return EXIT_SUCCESS;
}
