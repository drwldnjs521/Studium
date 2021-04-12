/* ptr12.c */
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

void kreisflaeche (float *wert) {
	*wert = (*wert) * (*wert) * PI;
}

int main(void) {
	float radius;
	
	printf("BERECHNUNG BEI EINER KREISFLAECHE!! ");	
	printf("\n\n Bitte Radius eingeben: ");
	scanf("%f", &radius);
	kreisflaeche(&radius);
	printf("Die Kreisflaeche betaegt: %f \n", radius);
	return EXIT_SUCCESS;
}
