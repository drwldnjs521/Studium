#include "tetrominos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Viel Erfolg!
 */
void anhaengenI(int *tetrominos, int x, int gesamtFelder) {
    int max = 0;
    int reihe = 0;
    for(int i = x; i < gesamtFelder; i += 10) {
        reihe++;
        if(tetrominos[i] != 8) {
            if(max < reihe) {
                max = reihe;
            }
        }
        
    }
    tetrominos[x+(10*max)] = 0;
    tetrominos[x+(10*max)+10] = 0;
    tetrominos[x+(10*max)+20] = 0;
    tetrominos[x+(10*max)+30] = 0;
    

}
void anhaengenQ(int *tetrominos, int x, int gesamtFelder) {
    int max = 0;
    int reihe = 0;
    for(int i = x; i < gesamtFelder; i += 10) {
        reihe++;
        if(tetrominos[i] != 8) {
            if(max < reihe) {
                max = reihe;
            }
        }
        if(tetrominos[i+1] != 8) {
            if(max < reihe) {
                max = reihe;
            }
        }
        
    }
    
    tetrominos[x+(10*max)] = 1;
    tetrominos[x+(10*max)+1] = 1;
    tetrominos[x+(10*max)+10] = 1;
    tetrominos[x+(10*max)+10+1] = 1;

}

void anhaengenT(int *tetrominos, int x, int gesamtFelder) {
    int max = 0;
    int reihe = 0;
    for(int i = x; i < gesamtFelder; i += 10) {
        reihe++;
        if(tetrominos[i] != 8) {
            if(max < reihe) {
                max = reihe;
            }
        }
        if(tetrominos[i+1] != 8) {
            if(max < reihe) {
                max = reihe;
            }
        }
        if(tetrominos[i+2] != 8) {
            if(max < reihe) {
                max = reihe;
            }
        }
    }
  
    tetrominos[x+(10*max)] = 2;
    tetrominos[x+(10*max)+1] = 2;
    tetrominos[x+(10*max)+2] = 2;
    tetrominos[x+(10*max)+10 + 1] = 2;


}

void anhaengenL(int *tetrominos, int x, int gesamtFelder) {
    int max = 0;
    int reihe = 0;
    for(int i = x; i < gesamtFelder; i += 10) {
        reihe++;
        if(tetrominos[i] != 8) {
            if(max < reihe) {
                max = reihe;
            }
        }
        if(tetrominos[i+1] != 8) {
            if(max < reihe) {
                max = reihe;
            }
        }
    }
   
    tetrominos[x+(10*max)] = 3;
    tetrominos[x+(10*max)+1] = 3;
    tetrominos[x+(10*max)+10] = 3;
    tetrominos[x+(10*max)+20] = 3;
   

}

void anhaengenS(int *tetrominos, int x, int gesamtFelder) {
    int max = 0;
    int reihe = 0;
    for(int i = x; i < gesamtFelder; i += 10) {
        reihe++;
        if(tetrominos[i] != 8) {
            if(max < reihe) {
                max = reihe;
            }
        }
        if(tetrominos[i+1] != 8) {
            if(max < reihe) {
                max = reihe;
            }
        }
    }
    for(int i = x+(10*max)+10+2; i < gesamtFelder; i += 10) {
        if(tetrominos[i] != 8) {
            max++;
        }
    }
    
    tetrominos[x+(10*max)] = 4;
    tetrominos[x+(10*max)+1] = 4;
    tetrominos[x+(10*max)+10+1] = 4;
    tetrominos[x+(10*max)+10+2] = 4;

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

void ausgeben(int *tetrominos, int maxHoehe, FILE *ausgabe) {
    int flag = 1;
    int temp = 0;
    for(int i = maxHoehe*10-1, k = 0; i != 0 && flag == 1; --i) {
        if(tetrominos[i] == 8) {
            ++k;
        }
        else {
            flag = 0;
            temp = i + k;
        }
        if (k == 10) {
            k = 0;
        }
    }
    for(int i = temp; i >= 9; i-=10) {
        for(int t = i-9; t <= i; t++) {
            if(tetrominos[t] == 8) {
                printf(" ");
                fputs(" ", ausgabe);
            }
            else {
                printf("%d", tetrominos[t]);
                fprintf(ausgabe, "%d", tetrominos[t]);
            }
        }
        printf("\n");
        fputs("\n", ausgabe);
    }
    
}


int main(int argc, char **argv){
    if (argc != 3){
        fprintf(stderr, "Zu wenige Parameter übergeben.\n");
        return 1;
    }
    FILE *eingabe = fopen(argv[1], "r");
    if(eingabe == NULL) {
        fprintf(stderr, "Eingabe Datei kann nicht geoeffnet werden.\n");
        return 2;
    }
    int maxHoehe = bloeckeAnzahl(eingabe) * 4;
    fclose(eingabe);

    FILE *eingabe2 = fopen(argv[1], "r");
    if(eingabe2 == NULL) {
        fprintf(stderr, "Eingabe Datei kann nicht geoeffnet werden.\n");
        return 2;
    }
    int* tetrominos = tetrominos_einlesen(eingabe2, maxHoehe);
    fclose(eingabe2);
    
    
    FILE *ausgabe = fopen(argv[2], "w");
    if(ausgabe == NULL) {
        fprintf(stderr, "Ausgabe Datei kann nicht geoeffnet werden.\n");
        return 2;
    }
    ausgeben(tetrominos, maxHoehe, ausgabe);
    fclose(ausgabe);

    tetrominos_freigeben(tetrominos);

    return 0;
}
