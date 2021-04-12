/* md_array1.c */
#include <stdlib.h>
#include <stdio.h>

#define VOL1 3
#define VOL2 4

int main(void) {
	int i,j;
	int myarray[VOL1][VOL2];
	
	for(i = 0; i < VOL1; i++) {
		for(j = 0; j < VOL2; j++) {
			printf("WERT für myarray[%d][%d] : ", i, j);
			scanf("%d", &myarray[i][j]);
		}
	}
	printf("\nAussage von myarray[%d][%d] --- \n\n", VOL1, VOL2);
	for(i = 0; i < VOL1; i++) {
		for(j = 0; j < VOL2; j++) {
			printf("\t%4d ", myarray[i][j]);
		}
		printf("\n\n");
	}
	return EXIT_SUCCESS;
}
