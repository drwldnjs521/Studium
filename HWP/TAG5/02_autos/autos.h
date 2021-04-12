#include "datum.h"
#include <stdio.h>
#include <string.h>

/*
 * Implementieren Sie hier:
 * - ein enum mit Namen fahrzeugklasse
 * - ein struct mit Namen fahrzeug.
 */
typedef enum {KOMBI, LIMO, MINIVAN, KLEINWAGEN} fahrzeugklasse;

typedef struct {
	char hersteller[100];
	char modell[100];
	int baujahr;
	char klimaanlage[100];
	datum erwerb;
	fahrzeugklasse klasse;
}fahrzeug;

void fahrzeug_einlesen(fahrzeug *einauto, FILE *eingabe);
void fahrzeug_ausgeben(fahrzeug *einauto, FILE *ausgabe);
fahrzeugklasse fahrzeugklasse_einlesen(char* klasse);
void fahrzeugklasse_ausgeben(fahrzeugklasse klasse, FILE *ausgabe);
fahrzeug* neuestes_fahrzeug(fahrzeug *autos, int anzahl);
