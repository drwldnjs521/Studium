//#include "tetrominos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Viel Erfolg!
 */
void anhaengenI(int *tetrominos, int x, int gesamtFelder) {
    int max = x;
    for(int i = x; i < gesamtFelder; i += 10) {
        if(tetrominos[i] != 8) {
            if(max < i) {
                max = i;
            }
        }
    }
    if(max == x) {
        tetrominos[max] = 0;
        tetrominos[max+10] = 0;
        tetrominos[max+20] = 0;
        tetrominos[max+30] = 0;
    }
    else {
        tetrominos[max+10] = 0;
        tetrominos[max+20] = 0;
        tetrominos[max+30] = 0;
        tetrominos[max+40] = 0;
    }
}
void anhaengenQ(int *tetrominos, int x, int gesamtFelder) {
    int max = x;
    for(int i = x; i < gesamtFelder; i += 10) {
        if(tetrominos[i] != 8) {
            if(max < i) {
                max = i;
            }
        }
        if(tetrominos[i+1] != 8) {
            if(max < i) {
                max = i;
            }
        }
    }
    if(max == x) {
        tetrominos[max] = 1;
        tetrominos[max+1] = 1;
        tetrominos[max+10] = 1;
        tetrominos[max+10 + 1] = 1;
    }
    else {
        tetrominos[max+10] = 1;
        tetrominos[max+10 + 1] = 1;
        tetrominos[max+20] = 1;
        tetrominos[max+20 + 1] = 1;
    }
}

void anhaengenT(int *tetrominos, int x, int gesamtFelder) {
    int max = x;
    for(int i = x; i < gesamtFelder; i += 10) {
        if(tetrominos[i] != 8) {
            if(max < i) {
                max = i;
            }
        }
        if(tetrominos[i+1] != 8) {
            if(max < i) {
                max = i;
            }
        }
        if(tetrominos[i+2] != 8) {
            if(max < i) {
                max = i;
            }
        }
    }
    if(max == x) {
        tetrominos[max] = 2;
        tetrominos[max+1] = 2;
        tetrominos[max+2] = 2;
        tetrominos[max+10 + 1] = 2;
    }
    else {
        tetrominos[max+10] = 2;
        tetrominos[max+10 + 1] = 2;
        tetrominos[max+10 + 2] = 2;
        tetrominos[max+20 + 1] = 2;
    }
}

void anhaengenL(int *tetrominos, int x, int gesamtFelder) {
    int max = x;
    for(int i = x; i < gesamtFelder; i += 10) {
        if(tetrominos[i] != 8) {
            if(max < i) {
                max = i;
            }
        }
        if(tetrominos[i+1] != 8) {
            if(max < i) {
                max = i;
            }
        }
    }
    if(max == x) {
        tetrominos[max] = 3;
        tetrominos[max+1] = 3;
        tetrominos[max+10] = 3;
        tetrominos[max+20] = 3;
    }
    else {
        tetrominos[max+10] = 3;
        tetrominos[max+10 + 1] = 3;
        tetrominos[max+20] = 3;
        tetrominos[max+30] = 3;
    }
}

void anhaengenS(int *tetrominos, int x, int gesamtFelder) {
    int max = x;
    for(int i = x; i < gesamtFelder; i += 10) {
        if(tetrominos[i] != 8) {
            if(max < i) {
                max = i;
            }
        }
        if(tetrominos[i+1] != 8) {
            if(max < i) {
                max = i;
            }
        }
        if(tetrominos[i+2] != 8) {
            if(max < i+10) {
                max = i+10;
            }
        }
    }
    if(max == x) {
        tetrominos[max] = 4;
        tetrominos[max+1] = 4;
        tetrominos[max+1 + 10] = 4;
        tetrominos[max+1 + 10 + 1] = 4;
    }
    else {
        tetrominos[max+10] = 4;
        tetrominos[max+10 +1] = 4;
        tetrominos[max+10 +1 + 10] = 4;
        tetrominos[max+10 +1 + 10 + 1] = 4;
    }
}


void anhaengen(int *tetrominos, int typ, int x, int gesamtFelder) {
    if(typ == 0) {
        anhaengenI(tetrominos, x, gesamtFelder);
    }
    else if(typ == 1) {
        anhaengenQ(tetrominos, x, gesamtFelder);
    }
    else if(typ == 2) {
        anhaengenT(tetrominos, x, gesamtFelder);
    }
    else if(typ == 3) {
        anhaengenL(tetrominos, x, gesamtFelder);
    }
    else if(typ == 4) {
        anhaengenS(tetrominos, x, gesamtFelder);
    }
}


int bloeckeAnzahl(FILE *eingabe) {
    int typ;
	int x;
    int zaehler = 0;
    while(fscanf(eingabe, "%d %d", &typ, &x) == 2) {
        zaehler++;
    }
    return zaehler;
}

int* tetrominos_einlesen(FILE *eingabe, int maxHoehe) {
	int typ;
	int x;
	int *tetrominos = (int*) malloc(10 * maxHoehe * sizeof(int));
    for(int i = 0; i < maxHoehe*10; ++i) {
        tetrominos[i] = 8;
    }
    while(fscanf(eingabe, "%d %d", &typ, &x) == 2) {
        anhaengen(tetrominos, typ, x, maxHoehe * 10);
    }	
	return tetrominos;
}

void tetrominos_freigeben(int *tetrominos) {
	free(tetrominos);
}

void ausgeben(int *tetrominos, int maxHoehe) {
    int flag = 1;
    int temp = 0;
    int i, k = 0;
    for(i = maxHoehe*10-1; i != 0 && flag == 1; --i) {
        if(tetrominos[i] == 8) {
            ++k;
        }
        else {
            flag = 0;
            temp = i + k;
            printf("%d", tetrominos[i]);
        }
        if (k == 10) {
            k = 0;
        }
    }
    printf("%d", temp);

    for(i = temp; i != 0; i-=9) {
        for(int t = i-9; t != i; t++) {
            if(tetrominos[i] == 8) {
                printf(" ");
            }
            else {
                printf("%d", tetrominos[i]);
            }
        }
        printf("\n");
    }
}


int main(int argc, char **argv){
    if (argc < 3){
        fprintf(stderr, "Zu wenige Parameter übergeben.\n");
        return EXIT_FAILURE;
    }
    FILE *eingabe = fopen(argv[1], "r");
    int maxHoehe = bloeckeAnzahl(eingabe) * 4;
    fclose(eingabe);

    FILE *eingabe2 = fopen(argv[1], "r");
    int* tetrominos = tetrominos_einlesen(eingabe2, maxHoehe);
    fclose(eingabe2);
    
    ausgeben(tetrominos, maxHoehe);

   // FILE *ausgabe = fopen(argv[2], "w");
    //tetrominos_ausgeben(tetrominos, ausgabe);
    //fclose(ausgabe);

    tetrominos_freigeben(tetrominos);

    return 0;
}
