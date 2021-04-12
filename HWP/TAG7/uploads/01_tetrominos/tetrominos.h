#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#define I 0
#define Q 1
#define T 2
#define L 3
#define S 4


struct Tetromino {
	int type;
	int x_achse;
	struct Tetromino *next;
}typedef Tetromino;

//ein senkrechter Balken
int i[8]={0,0,0,1,0,2,0,3};	
//ein quadratischer 2x2 Block
int q[8]={0,0,0,1,1,0,1,1};
//ein Form des umgedrehten Buchstaben T
int t[8]={0,0,1,0,1,1,2,0};
//S-förmig
int s[8]={0,0,1,0,1,1,2,1};
//L-förmig
int l[8]={0,0,1,0,1,1,2,1};


Tetromino* anhaengen(Tetromino *tetrominos, int type, int x_achse);
int(*belegen(char **spielfeld, Tetromino *tetrominos))[10];
void tetrominos_ausgeben(Tetromino *tetrominos, FILE *ausgabe);
Tetromino* tetrominos_einlesen(FILE *eingabe);
void tetrominos_freigeben(Tetromino *tetrominos);
*/
void anhaengenI(int *tetrominos, int x, int gesamtFelder);
void anhaengenQ(int *tetrominos, int x, int gesamtFelder);

void anhaengenT(int *tetrominos, int x, int gesamtFelder);

void anhaengenS(int *tetrominos, int x, int gesamtFelder);


void anhaengen(int *tetrominos, int typ, int x, int gesamtFelder);

int bloeckeAnzahl(FILE *eingabe);

int* tetrominos_einlesen(FILE *eingabe, int maxHoehe);

void tetrominos_freigeben(int *tetrominos);

void ausgeben(int *tetrominos, int maxHoehe);
