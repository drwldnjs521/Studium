#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int main(void) {
	int i;
	int array1[MAX], array2[MAX];
	
	for(i = 0; i < MAX; i++) {
		array1[i] = i;
		array2[i] = i;
	}
	array2[5] = 100;
	
	for(i = 0; i < MAX; i++) {
		if(array1[i] == array2[i] ) {
			continue;
		}else{
			printf("UNTERSCHIED AN POSITION %d\n", i);
			break;
		}
		
	}
	return EXIT_SUCCESS;
}
