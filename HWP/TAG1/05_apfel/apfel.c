#include <stdio.h>
#include <stdlib.h>
#define APFEL 1 
#define MAX 45

/*
 * Nimmt Tastatureingabe vom Benutzer entgegen und gibt die eingegebene Zahl zurück.
 */
int warte_auf_eingabe() {
	int z;
	printf("Wie viele Äpfel möchten Sie haben?\n");
	scanf("%d", &z);
	if(z <  0)
		return 0;
	else {
		printf("%d Äpfel müssen gegeben werden.\n", z);
		return z;
	}
 }

/*
 * Gibt "anzahl" Äpfel aus und passt die übergebenen Geld- und Apfelbestände
 * des Automaten entsprechend an.
 */
void apfel_ausgeben(int anzahl, double *geldstand, int *apfelstand) {
			
	*geldstand += APFEL * anzahl; 
	*apfelstand -= anzahl;
	
	printf("Äpfel = %d\n", *apfelstand);
		
}

/*
 * Ausgabe eines Apfels.
 */


void print_apfel(){
    printf("        |/\n");
    printf("   ___  | ___ \n");
    printf("  /    \\|/    \\\n");
    printf(" /             \\\n");
    printf("|      APFEL    |\n");
    printf("|               |\n");
    printf(" \\             /\n");
    printf("  \\____/|\\____/\n");
}

int main(void) {
	
	int gesamte_Apfel = 500;
	double gesamtes_Geld = 0;
	int eingabe = 0;
	
	do {
		eingabe = warte_auf_eingabe();
	
		if(eingabe == 0)
			return 0;
		else if(gesamte_Apfel < eingabe) {
			printf("Nur noch %d Äpfel übring.\n", gesamte_Apfel);
			for(int i = 0; i < gesamte_Apfel; i++)
				print_apfel();
			apfel_ausgeben(gesamte_Apfel, &gesamtes_Geld, &gesamte_Apfel);			
		} else {
			for(int i = 0; i < eingabe; i++)
				print_apfel();
			apfel_ausgeben(eingabe, &gesamtes_Geld, &gesamte_Apfel);		
		}
		
		if(gesamtes_Geld >= MAX)
			printf("Kasse muss geleert werden.\n");
			
	}while(gesamte_Apfel > 0);
	
	printf("Kein Apfel ist im Automat.\n");
	
	return EXIT_SUCCESS;
		
	
}
