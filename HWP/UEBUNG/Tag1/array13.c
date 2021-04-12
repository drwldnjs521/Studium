#include<stdio.h>
#include<stdlib.h>

#define SPIELE 5
#define WIN 3
#define LOSE 0
#define REMIS 1

int Bayern[SPIELE] = { 0 };
int Borussia[SPIELE] = { 0 };

void punkte(int bm[], int bd[], int count) {
	if(bm[count] > bd[count] ) {
		bm[count] = WIN;
		bd[count] = LOSE;
	}
	else if(bm[count] < bd[count]) {
		bm[count] = LOSE;
		bd[count] = WIN;
	}
	else if(bm[count] == bd[count]) {
		bm[count] = bd[count] = REMIS;
	}
}

int main(void) {
	unsigned int tor1, tor2;
	unsigned int tmptor1 = 0, tmptor2 = 0;
	unsigned int punkte_bay = 0, punkte_bor = 0;
	unsigned int count = 0;
	
	printf("EINGEBE DER LETZTEN %d SPIELE \n\n", SPIELE); 
	
	while(count != SPIELE) {
		printf("%d. Spiel : Bayern - Borrusia\n", count+1);
		printf("TOR(E) Bayern : ");
		scanf("%2u", &tor1);
		Bayern[count] = tor1;
		printf("TOR(E) BORUSSIA : ");
		scanf("%2u", &tor2);
		Borussia[count] = tor2;
		
		tmptor1 += tor1;
		tmptor2 += tor2;
		
		punkte(Bayern, Borussia, count);
		
		punkte_bay += Bayern[count];
		punkte_bor += Borussia[count];
		count++;
	}
	
	printf("BAYERN - BORUSSIA\n");
	printf("PUNKTE : %2d : %2d\n", punkte_bay, punkte_bor);
	printf("Tore : %2d : %2d\n", tmptor1, tmptor2);
	return EXIT_SUCCESS;
}
