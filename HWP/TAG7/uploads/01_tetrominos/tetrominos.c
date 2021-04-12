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
		tetrominos = (Tetromino*)malloc(sizeof(Tetromino));
		tetrominos->type = type;
		tetrominos->x_achse = x_achse;
		tetrominos->next = NULL;
	}
	else {
		zeiger = tetrominos;
		
		while(zeiger->next != NULL) 
			zeiger = zeiger->next;
			
		zeiger->next = (Tetromino*)malloc(sizeof(Tetromino));
		zeiger->type = type;
		zeiger->x_achse = x_achse;
		zeiger->next = NULL;
	}
	
	return tetrominos;
		
}

int(*belegen(char **spielfeld, Tetromino *tetrominos))[10] {
	int y_achse[10] = {0,};
	int y = 0,i = 0, j = 0,tmp = 0;
	
	spielfeld = (char**)malloc(sizeof(char*) * 200);
	for(i = 0; i < 200; i++) {
		spielfeld[i] = (char*)malloc(sizeof(char*) * 11);
		spielfeld[i][10] = '\n';
	}
		
	while(tetrominos != NULL) {
		switch(tetrominos->type) {
			//ein senkrechter Balken
			case 0:
				y = y_achse[tetrominos->x_achse];
				for(i = y; i < y + 4 ; i++) 
					spielfeld[tetrominos->x_achse][y] = 0;
				
				y_achse[tetrominos->x_achse] += 4;
				
			
			//ein quadratischer 2x2 Block
			case 1:
				y = y_achse[tetrominos->x_achse];
				if((spielfeld[tetrominos->x_achse][y] == " ") && (spielfeld[(tetrominos->x_achse)+1][y] == " ")) {
					for(i = tetrominos->x_achse; i < tetrominos->x_achse + 2; i++) {
						for(j = y; j < y + 2; j++) 
							spielfeld[i][j] = 0;
					}
				}
				else {
					y = (y_achse[tetrominos->x_achse] > y_achse[(tetrominos->x_achse)+1]) ? y_achse[tetrominos->x_achse] : y_achse[(tetrominos->x_achse)+1]); 
					for(i = tetrominos->x_achse; i < (tetrominos->x_achse) + 2; i++) {
						for(j = y; j < y + 2; j++) 
							spielfeld[i][j] = 0;
					}
					
				}
				y_achse[tetrominos->x_achse] += 2;
				y_achse[(tetrominos->x_achse)+1] += 2;
					
				
			//ein Form des umgedrehten Buchstaben T		
			case 2:
				y = y_achse[tetrominos->x_achse];
				if((spielfeld[tetrominos->x_achse][y] == " ") && (spielfeld[(tetrominos->x_achse)+1][y] == " ") && (spielfeld[(tetrominos->x_achse)+2][y] == " ")) {
					for(i = tetrominos->x_achse; i < (tetrominos->x_achse) + 3; i++) {
						for(j = y; j < y + 2; j++) 
							spielfeld[i][j] = 0;
					}
					spielfeld[tetrominos->x_achse][y] = " ";
					spielfeld[(tetrominos->x_achse)+2][y] = " ";
				}
				
				else {
					tmp = (y_achse[tetrominos->x_achse] > y_achse[(tetrominos->x_achse)+1]) ? y_achse[tetrominos->x_achse] : y_achse[(tetrominos->x_achse)+1]); 
					y = ((tmp > y_achse[(tetrominos->x_achse)+3]) ? tmp : y_achse[(tetrominos->x_achse)+3]); 
					for(i = tetrominos->x_achse; i < (tetrominos->x_achse) + 3; i++) {
						for(j = y; j < y + 2; j++) 
							spielfeld[i][j] = 0;
					}
					spielfeld[tetrominos->x_achse][y] = " ";
					spielfeld[(tetrominos->x_achse)+2][y] = " ";
				}
				y_achse[tetrominos->x_achse] += 2;
				y_achse[(tetrominos->x_achse)+1] += 2;
			//S-förmig
			case 3:
				y = y_achse[tetrominos->x_achse];
				if((spielfeld[tetrominos->x_achse][y] == " ") && (spielfeld[(tetrominos->x_achse)+1][y] == " ") && (spielfeld[(tetrominos->x_achse)+2][y+1] == " ")) {
					for(i = tetrominos->x_achse; i < (tetrominos->x_achse) + 3; i++) {
						for(j = y; j < y + 2; j++) 
							spielfeld[i][j] = 0;
					}
					spielfeld[tetrominos->x_achse][y] = " ";
					spielfeld[(tetrominos->x_achse)+2][y] = " ";
				}
				
				else {
					tmp = (y_achse[tetrominos->x_achse] > y_achse[(tetrominos->x_achse)+1]) ? y_achse[tetrominos->x_achse] : y_achse[(tetrominos->x_achse)+1]); 
					y = ((tmp > y_achse[(tetrominos->x_achse)+3]) ? tmp : y_achse[(tetrominos->x_achse)+3]); 
					for(i = tetrominos->x_achse; i < (tetrominos->x_achse) + 3; i++) {
						for(j = y; j < y + 2; j++) 
							spielfeld[i][j] = 0;
					}
					spielfeld[tetrominos->x_achse][y] = " ";
					spielfeld[(tetrominos->x_achse)+2][y] = " ";
				}
				y_achse[tetrominos->x_achse] += 2;
				y_achse[(tetrominos->x_achse)+1] += 2;
			//L-förmig
			case 4:
				y = y_achse[tetrominos->x_achse];
				if((spielfeld[tetrominos->x_achse][y] == " ") && (spielfeld[(tetrominos->x_achse)+1][y] == " ")) {
					for(i = tetrominos->x_achse; i < (tetrominos->x_achse) + 3; i++) {
						for(j = y; j < y + 1; j++) 
							spielfeld[i][j] = 0;
					}
					spielfeld[tetrominos->x_achse][y] = " ";
					spielfeld[(tetrominos->x_achse)+2][y] = " ";
				}
				
				else {
					tmp = (y_achse[tetrominos->x_achse] > y_achse[(tetrominos->x_achse)+1]) ? y_achse[tetrominos->x_achse] : y_achse[(tetrominos->x_achse)+1]); 
					y = ((tmp > y_achse[(tetrominos->x_achse)+3]) ? tmp : y_achse[(tetrominos->x_achse)+3]); 
					for(i = tetrominos->x_achse; i < (tetrominos->x_achse) + 3; i++) {
						for(j = y; j < y + 2; j++) 
							spielfeld[i][j] = 0;
					}
					spielfeld[tetrominos->x_achse][y] = " ";
					spielfeld[(tetrominos->x_achse)+2][y] = " ";
				}
				y_achse[tetrominos->x_achse] += 2;
				y_achse[(tetrominos->x_achse)+1] += 2;
		}
		tetrominos = tetrominos->next;
	}
	
	tetrominos_freigeben(tetrominos);
	return spielfeld;
}

void tetrominos_ausgeben(Tetromino *tetrominos, FILE *ausgabe) {
	
	
	
	Tetromino *zeiger = tetrominos;
	
	while(zeiger != NULL){
		fscanf(ausgabe, "%ls", zeiger->form);
		zeiger = zeiger->next;
	}
	 
}


Tetromino* tetrominos_einlesen(FILE *eingabe) {
	
	int type;
	int x_achse;
	Tetromino *tetrominos = NULL;
	
	while(fscanf(eingabe, "%d %d", &type, &x_achse) == 2) {
		tetrominos = anhaengen(tetrominos, type, x_achse);
	
	return tetrominos;
		
}

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


int main(int argc, char **argv){
    if (argc < 3){
        fprintf(stderr, "Zu wenige Parameter übergeben.\n");
        return EXIT_FAILURE;
    }

    // Fahrzeuge einlesen.
    FILE *eingabe = fopen(argv[1], "r");
    Tetromino* tetrominos = tetrominos_einlesen(eingabe);
    fclose(eingabe);
    
    int (*spielfeld)[10] = belegen
/*
    // Fahrzeuge ausgeben.
    FILE *ausgabe = fopen(argv[2], "w");
    tetrominos_ausgeben(tetrominos, ausgabe);
    fclose(ausgabe);

    tetrominos_freigeben(tetrominos);
*/
    return 0;
}
