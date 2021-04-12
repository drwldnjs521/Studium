#include "datum.h"
#include <stdio.h>
#include <string.h>

/*
 * Implementieren Sie hier:
 * - ein enum mit Namen fahrzeugklasse
 * - ein struct mit Namen fahrzeug.
 */









void fahrzeug_einlesen(fahrzeug *einauto, FILE *eingabe);
void fahrzeug_ausgeben(fahrzeug *einauto, FILE *ausgabe);
fahrzeugklasse fahrzeugklasse_einlesen(char* klasse);
void fahrzeugklasse_ausgeben(fahrzeugklasse klasse, FILE *ausgabe);
fahrzeug* neuestes_fahrzeug(fahrzeug *autos, int anzahl);
