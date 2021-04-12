#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Implementieren Sie hier ein struct mit Namen fahrzeug. */





/* Implementieren Sie die folgenden Funktionen. */
fahrzeug* fahrzeug_vorne_anhaengen(fahrzeug *fahrzeuge, char *name);
fahrzeug* fahrzeug_hinten_anhaengen(fahrzeug *fahrzeuge, char *name);
void fahrzeuge_ausgeben(fahrzeug *fahrzeuge, FILE *ausgabe);
fahrzeug* fahrzeug_finden(fahrzeug *fahrzeuge, char *name);
fahrzeug* fahrzeuge_einlesen(FILE *eingabe);
void fahrzeuge_freigeben(fahrzeug *fahrzeuge);







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
