/* datum.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datum.h"


datum neues_datum(int jahr, int monat, int tag) {
	
	datum a;
	
	a.jahr = jahr;
	a.monat = monat;
	a.tag = tag;
	
	return a;
	
}


void datum_ausgeben(datum d, FILE *ausgabe) {
	
	fprintf(ausgabe, "%4d-%02d-%02d\n", d.jahr, d.monat, d.tag);
	
}
 
int datum_vergleichen(datum a, datum b) {
	
    if(a.jahr == b.jahr) {
		if(a.monat == b.monat) {
			if(a.tag == b.tag) 
				return 0;
			else if (a.tag < b.tag)
				return -1;
			else
				return 1;
		}
		else if(a.monat < b.monat)
			return -1;
		else
			return 1;
		}
	else if (a.jahr < b.jahr) 
		return -1;
	else return 1;
     
}
