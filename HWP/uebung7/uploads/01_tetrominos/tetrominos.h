 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void anhaengenI(int *tetrominos, int x, int gesamtFelder);
void anhaengenQ(int *tetrominos, int x, int gesamtFelder);
void anhaengenT(int *tetrominos, int x, int gesamtFelder);
void anhaengenL(int *tetrominos, int x, int gesamtFelder);
void anhaengenS(int *tetrominos, int x, int gesamtFelder);
void anhaengen(int *tetrominos, int typ, int x, int gesamtFelder);
int bloeckeAnzahl(FILE *eingabe);
int* tetrominos_einlesen(FILE *eingabe, int maxHoehe);
void tetrominos_freigeben(int *tetrominos);
void ausgeben(int *tetrominos, int maxHoehe, FILE *ausgabe);
