/* dyn_matrix.c */
#include <stdio.h>
#include <stdlib.h>
#define BUF 255

int main(void) {
	int i,j,spalte, zeile;
	int **matrix;
	
	printf("Wie viele Zeile: ");
	scanf("%d", &zeile);
	printf("Wie viele Spalte: ");
	scanf("%d", &spalte);
	
	matrix = malloc(zeile * sizeof(int *));
	
	if(matrix == NULL) {
		printf("Kein virtueller RAM ist vorhanden\n");
		return EXIT_FAILURE;
	}
	
	for(i = 0; i < zeile; i++) {
		matrix[i] = malloc(spalte * sizeof(int));
		if(matrix[i] == NULL) {
			printf("Kein virtueller RAM ist vorhanden\n");
			return EXIT_SUCCESS;
		}
	}
	
	for(i = 0; i < zeile; i++) {
		for(j = 0; j < spalte; j++) 
			printf("matrix[%d][%d] = %d " , i,j,i + j) ;
	}
	
	for(j = 0; j < zeile; j++) 
		free(matrix[j]);
		
	free(matrix);
	
	return EXIT_SUCCESS;
}

		
