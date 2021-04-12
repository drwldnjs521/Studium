/* str14.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *function1(void) {
	static char puffer[10];
	strcpy(puffer, "testwert");
	return puffer;
}

char *function2(void) {
	char *ptr = (char *)malloc(sizeof(char) * 10);
	strcpy(ptr, "testwert");
	return ptr;
}

char *function3(char *ptr) {
	char buffer[10];
	ptr = buffer;
	strcpy(str, "testwert");
	return str;
}
