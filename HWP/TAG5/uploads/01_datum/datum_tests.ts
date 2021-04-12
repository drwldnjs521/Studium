#include "datum.h"
#include <stdio.h>

#test datum_ist_gleich
    datum a = neues_datum(2020, 12, 24);
    datum b = neues_datum(2020, 12, 24);
    ck_assert_int_eq(datum_vergleichen(a, b), 0);
    ck_assert_int_eq(datum_vergleichen(b, a), 0);

#test datum_ist_davor
    datum a = neues_datum(2019, 11, 1);
    datum b = neues_datum(2020, 12, 2);
    ck_assert_int_eq(datum_vergleichen(a, b), -1);
    ck_assert_int_eq(datum_vergleichen(b, a), 1);

#test datum_ist_danach
    datum a = neues_datum(2020, 12, 1);
    datum b = neues_datum(2020, 11, 1);
    ck_assert_int_eq(datum_vergleichen(a, b), 1);
    ck_assert_int_eq(datum_vergleichen(b, a), -1);

#test datum_ist_davor_gleicher_monat_gleiches_jahr
    datum a = neues_datum(2020, 8, 30);
    datum b = neues_datum(2020, 8, 31);
    ck_assert_int_eq(datum_vergleichen(a, b), -1);
    ck_assert_int_eq(datum_vergleichen(b, a), 1);

#test datum_ausgabe_zweistellig
    /* Datum in eine Datei schreiben. */
    FILE *ausgabe = fopen("ausgabe.txt", "w");
    datum d = neues_datum(2020, 12, 30);
    datum_ausgeben(d, ausgabe);
    fclose(ausgabe);

    /* Datum aus Datei lesen und vergleichen. */
    FILE *f = fopen("ausgabe.txt", "r");
    char text[11];
    fgets(text, sizeof(text), f);
    printf("Datum: %s\n", text);
    fclose(f);
    ck_assert_str_eq(text, "2020-12-30");

#test datum_ausgabe_einstellig
    /*
     * Falls Sie Probleme mit diesem Test haben, recherchieren Sie, wie man mit
     * printf führende Nullen ausgibt.
     */

    /* Datum in eine Datei schreiben. */
    FILE *ausgabe = fopen("ausgabe.txt", "w");
    datum d = neues_datum(1970, 1, 1);
    datum_ausgeben(d, ausgabe);
    fclose(ausgabe);

    /* Datum aus Datei lesen und vergleichen. */
    FILE *f = fopen("ausgabe.txt", "r");
    char text[11];
    fgets(text, sizeof(text), f);
    printf("Datum: %s\n", text);
    fclose(f);
    ck_assert_str_eq(text, "1970-01-01");
