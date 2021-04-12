#include "tetrominos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Viel Erfolg!
 */


Tetromino* anhaengen(Tetromino *tetrominos, int type, int x_achse) {
	
	Tetromino *zeiger;
	
	if(tetrominos == NULL) {
		tetrominos = malloc(sizeof(Tetromino));
		tetrominos->type = type;
		tetrominos->form = malloc(sizeof(int) * 8);
		switch(type) {
			case 0:
				memcpy(tetrominos->form, i, (sizeof(int) * 8));
			case 1:
				memcpy(tetrominos->form, q, (sizeof(int) * 8));
			case 2:
				memcpy(tetrominos->form, t, (sizeof(int) * 8));
			case 3:
				memcpy(tetrominos->form, s, (sizeof(int) * 8));
			case 4:
				memcpy(tetrominos->form, l, (sizeof(int) * 8));
		}
		for(int i = 0; i < 6; i++) {
			if(i % 2 != 0) {
				tetrominos->form[i] += x_achse;
			}
		}
		tetrominos->next = NULL;
	} else {
		zeiger = tetrominos;
		
		while(zeiger->next != NULL) 
			zeiger = zeiger->next;
			
		zeiger->next = malloc(sizeof(Tetromino));
		zeiger = zeiger->next;
		zeiger->type = type;
		zeiger->form = malloc(sizeof(int) * 8);
		switch(type) {
			case 0:
				memcpy(zeiger->form, i, (sizeof(int) * 8));
			case 1:
				memcpy(zeiger->form, q, (sizeof(int) * 8));
			case 2:
				memcpy(zeiger->form, t, (sizeof(int) * 8));
			case 3:
				memcpy(zeiger->form, s, (sizeof(int) * 8));
			case 4:
				memcpy(zeiger->form, l, (sizeof(int) * 8));
		}
		for(int i = 0; i < 6; i++) {
			if(i % 2 != 0) {
				zeiger->form[i] += x_achse;
			}
		}
		zeiger->next = NULL;
		
	}
	
	return tetrominos;
		
}
/*
void tetrominos_ausgeben(Tetromino *tetrominos, FILE *ausgabe) {
	
	//int spielfeld[][10];
	
	Tetromino *zeiger = tetrominos;
	
	while(zeiger != NULL){
		fscanf(ausgabe, "%ls", zeiger->form);
		zeiger = zeiger->next;
	}
	 
}
*/

Tetromino* tetrominos_einlesen(FILE *eingabe) {
	
	int type;
	int x_achse;
	Tetromino *tetrominos = NULL;
	
	while(fscanf(eingabe, "%d %d", &type, &x_achse) == 2)
		tetrominos = anhaengen(tetrominos, type, x_achse);
		
	return tetrominos;
		
}
/*
void tetrominos_freigeben(Tetromino *tetrominos) {
	
	Tetromino *tmp, *next;
	tmp = tetrominos;
	
	while(tmp != NULL) {
		next = tmp->next;
		free(tmp->form);
		free(tmp);
		tmp = next;
	}

}
*/

int main(int argc, char **argv){
    if (argc < 3){
        fprintf(stderr, "Zu wenige Parameter übergeben.\n");
        return EXIT_FAILURE;
    }

    // Fahrzeuge einlesen.
    FILE *eingabe = fopen(argv[1], "r");
    Tetromino* tetrominos = tetrominos_einlesen(eingabe);
    int i = 2;
    while(tetrominos != NULL) {
		//printf("%d\n", i);
		i++;
		tetrominos = tetrominos->next;
	}
    fclose(eingabe);
/*
    // Fahrzeuge ausgeben.
    FILE *ausgabe = fopen(argv[2], "w");
    tetrominos_ausgeben(tetrominos, ausgabe);
    fclose(ausgabe);

    tetrominos_freigeben(tetrominos);
*/
    return 0;
}
