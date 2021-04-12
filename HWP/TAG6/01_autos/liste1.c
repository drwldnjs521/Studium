#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Implementieren Sie hier ein struct mit Namen fahrzeug. */
struct fahrzeug{
	char name[30];
	struct fahrzeug *next;
}typedef fahrzeug;

/* Implementieren Sie die folgenden Funktionen. 
fahrzeug* fahrzeug_vorne_anhaengen(fahrzeug *fahrzeuge, char *name) {
	fahrzeug *zeiger;
	zeiger = fahrzeuge;
	
	fahrzeuge = malloc(sizeof(fahrzeug)); 
	strcpy(fahrzeuge->name, name);
	fahrzeuge->next = zeiger;
	
	return fahrzeuge;
	
}
* */ 
fahrzeug* fahrzeug_vorne_anhaengen(fahrzeug *fahrzeuge, char *name) {
	fahrzeug *zeiger;
	zeiger = (fahrzeug*)malloc(sizeof(fahrzeug)); 
	
	strcpy(zeiger->name, name);
	zeiger->next = fahrzeuge;
	
	return zeiger;
	
}
fahrzeug* fahrzeug_hinten_anhaengen(fahrzeug *fahrzeuge, char *name) {
	
	fahrzeug *zeiger;
	
	zeiger = fahrzeuge;
	while(zeiger->next != NULL) 
		zeiger = zeiger->next;
	
	zeiger->next = malloc(sizeof(fahrzeug));
	zeiger = zeiger->next;
	strcpy(zeiger->name, name);
	zeiger->next = NULL;
	
	return fahrzeuge;
}

void fahrzeuge_ausgeben(fahrzeug *fahrzeuge, FILE *ausgabe) {
	fahrzeug *zeiger = fahrzeuge;
	
	while(zeiger != NULL){
		fputs(zeiger->name, ausgabe);
		zeiger = zeiger->next;
	}
		 
}

fahrzeug* fahrzeug_finden(fahrzeug *fahrzeuge, char *name) {
	
	fahrzeug *zeiger;
	zeiger = fahrzeuge;
	
	while(zeiger != NULL) {
		if(strcmp(name, zeiger->name) == 0) 
			return zeiger;
		else zeiger = zeiger->next;
	}
	return NULL;
}

fahrzeug* fahrzeuge_einlesen(FILE *eingabe) {
	
	char n[30];
	fahrzeug *anfang = NULL;
	
	while(fgets(n, 30, eingabe) != NULL) {
		if(anfang == NULL) {
			anfang = (fahrzeug*)malloc(sizeof(fahrzeug));
			strcpy(anfang->name, n);
			anfang->next = NULL;
		} else {
			if(fahrzeug_finden(anfang, n) == NULL)
				anfang = fahrzeug_vorne_anhaengen(anfang, n);
			else fahrzeug_hinten_anhaengen(anfang, n);
		}
	}
	return anfang;
		
}

void fahrzeuge_freigeben(fahrzeug *fahrzeuge) {
	
	fahrzeug *tmp, *next;
	tmp = fahrzeuge;
	
	while(tmp != NULL) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}

}




int main(int argc, char **argv){
    if (argc < 3){
        fprintf(stderr, "Zu wenige Parameter übergeben.\n");
        return EXIT_FAILURE;
    }

    // Fahrzeuge einlesen.
    FILE *eingabe = fopen(argv[1], "r");
    fahrzeug* fahrzeuge = fahrzeuge_einlesen(eingabe);
    fclose(eingabe);

    // Fahrzeuge ausgeben.
    FILE *ausgabe = fopen(argv[2], "w");
    fahrzeuge_ausgeben(fahrzeuge, ausgabe);
    fclose(ausgabe);

    fahrzeuge_freigeben(fahrzeuge);

    return 0;
}
