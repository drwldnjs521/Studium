#include "autos.h"
#include <string.h>


void fahrzeug_einlesen(fahrzeug *einauto, FILE *eingabe){
    /*
     * Implementieren Sie hier das einlesen von Fahrzeugen.
     
    char hersteller[100];
	char modell[100];
	int baujahr;
	char klimaanlage[100];
	int tag, monat, jahr;
 */
	char fahrzeug_klasse[15];
    
    fscanf(eingabe, "%s %s %d %s %d %d %d %s", einauto->hersteller, einauto->modell, &einauto->baujahr, einauto->klimaanlage, &einauto->erwerb.tag, &einauto->erwerb.monat, &einauto->erwerb.jahr, fahrzeug_klasse);
	einauto->klasse = fahrzeugklasse_einlesen(fahrzeug_klasse);
	
	

}

fahrzeug* neuestes_fahrzeug(fahrzeug *autos, int anzahl) { 
	
	
    /*
     * Suchen Sie hier das Fahrzeug, mit dem neusten Erwerbsdatum
     * und geben Sie es als Pointer zurück.
     */
	fahrzeug *tmp; 
	tmp = autos;
	for(int i = 1; i < 10; i++) {
		if(datum_vergleichen(tmp->erwerb, (autos + i)->erwerb) == -1)
			tmp = (autos + i);
	}
	
	return tmp;
}

	
