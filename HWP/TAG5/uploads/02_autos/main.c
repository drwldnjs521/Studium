#include "autos.h"

int main(int argc, char **argv){
    FILE *eingabe = stdin;
    FILE *ausgabe = stdout;

    fahrzeug autos[10];

    /* Autos einlesen. */
    for (int i = 0; i < 10; i++){
        fahrzeug *einauto = &autos[i];

        fahrzeug_einlesen(einauto, eingabe);
    }

    /* Autos ausgeben. */
    for (int i = 0; i < 10; i++){
        fprintf(ausgabe, "Auto %i:\n", i + 1);

        fahrzeug *einauto = &autos[i];

        fahrzeug_ausgeben(einauto, ausgabe);
    }

    /* Das neuste Auto ausgeben. */
    fprintf(ausgabe, "Das neuste Auto ist:\n");
    fahrzeug *neustes = neuestes_fahrzeug(autos, 10);
    fahrzeug_ausgeben(neustes, ausgabe);

    return 0;
}

fahrzeugklasse fahrzeugklasse_einlesen(char* klasse){
    if (strcmp(klasse, "Kombi") == 0) return KOMBI;
    if (strcmp(klasse, "Minivan") == 0) return MINIVAN;
    if (strcmp(klasse, "Limousine") == 0) return LIMO;
    return KLEINWAGEN;
}

void fahrzeugklasse_ausgeben(fahrzeugklasse klasse, FILE *ausgabe){
    switch (klasse){
        case KOMBI:
            fprintf(ausgabe, "Kombi\n");
            break;
        case MINIVAN:
            fprintf(ausgabe, "Minivan\n");
            break;
        case LIMO:
            fprintf(ausgabe, "Limousine\n");
            break;
        default:
            fprintf(ausgabe, "Kleinwagen\n");
    }
}

void fahrzeug_ausgeben(fahrzeug *einauto, FILE *ausgabe){
    fprintf(
        ausgabe,
        "***********************************************\n"
        "    Hersteller : %s\n"
        "    Modell     : %s\n"
        "    Baujahr    : %i\n"
        "    Klimaanlage: %s\n"
        "    Erwerb     : ",
        einauto->hersteller,
        einauto->modell,
        einauto->baujahr,
        einauto->klimaanlage
    );

    datum_ausgeben(einauto->erwerb, ausgabe);

    fprintf(ausgabe, "    Klasse     : ");
    fahrzeugklasse_ausgeben(einauto->klasse, ausgabe);

    fprintf(ausgabe, "***********************************************\n");
}
