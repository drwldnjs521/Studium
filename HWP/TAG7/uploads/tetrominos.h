#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define I 0
#define Q 1
#define T 2
#define L 3
#define S 4

/*	
const int tetrominos[5][4][3] = {
	//I
	{{1,0,0},{1,0,0},{1,0,0},{1,0,0}},
	//Q
	{{0,0,0},{0,1,1},{0,1,1},{0,0,0}}, 
	//T
	{{0,0,0},{0,1,0},{1,1,1},{0,0,0}},
	//S
	{{0,0,0},{1,1,0},{0,1,1},{0,0,0}}, 
	//L
	{{0,0,0},{0,1,0},{0,1,0},{0,1,1}}
};
*/

const int I[4][3] = {{1,0,0},{1,0,0},{1,0,0},{1,0,0}};
const int Q[4][3] = {{0,0,0},{0,1,1},{0,1,1},{0,0,0}};
const int T[4][3] = {{0,0,0},{0,1,0},{1,1,1},{0,0,0}};
const int S[4][3] = {{0,0,0},{1,1,0},{0,1,1},{0,0,0}};
const int L[4][3] = {{0,0,0},{0,1,0},{0,1,0},{0,1,1}};

typedef struct tetromino {
	int type;
	int *form;
};

tetromino* anhaengen(Tetromino *tetrominos, int type, int x_achse);
void tetrominos_ausgeben(tetromino *tetrominos, FILE *ausgabe);
tetromino* tetrominos_einlesen(FILE *eingabe);
void tetrominos_freigeben(tetromino *tetrominos);

