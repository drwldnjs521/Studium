#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

int main(void) {
	int i; 
	int array1[MAX];
	int array2[MAX];
	
	for(i = 0; i < MAX; i++) {
		array1[i] = i;
		array2[i] = i;
	}
	
	array2[5] = 100;
	
	if(memcmp(array1, array2, sizeof(array1)) == 0) {
		printf("BEIDE ARRAYS HABEN DEN GLEICHEN INHALT\n");
	}else 
		printf("DIE ARRAYS SIND UNTERSCHIEDLICH\n");
	
	return EXIT_SUCCESS;
}
