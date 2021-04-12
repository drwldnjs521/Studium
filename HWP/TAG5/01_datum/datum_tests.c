/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "datum_tests.ts" instead.
 */

#include <check.h>

#line 1 "datum_tests.ts"
#include "datum.h"
#include <stdio.h>

START_TEST(datum_ist_gleich)
{
#line 5
    datum a = neues_datum(2020, 12, 24);
    datum b = neues_datum(2020, 12, 24);
    ck_assert_int_eq(datum_vergleichen(a, b), 0);
    ck_assert_int_eq(datum_vergleichen(b, a), 0);

}
END_TEST

START_TEST(datum_ist_davor)
{
#line 11
    datum a = neues_datum(2019, 11, 1);
    datum b = neues_datum(2020, 12, 2);
    ck_assert_int_eq(datum_vergleichen(a, b), -1);
    ck_assert_int_eq(datum_vergleichen(b, a), 1);

}
END_TEST

START_TEST(datum_ist_danach)
{
#line 17
    datum a = neues_datum(2020, 12, 1);
    datum b = neues_datum(2020, 11, 1);
    ck_assert_int_eq(datum_vergleichen(a, b), 1);
    ck_assert_int_eq(datum_vergleichen(b, a), -1);

}
END_TEST

START_TEST(datum_ist_davor_gleicher_monat_gleiches_jahr)
{
#line 23
    datum a = neues_datum(2020, 8, 30);
    datum b = neues_datum(2020, 8, 31);
    ck_assert_int_eq(datum_vergleichen(a, b), -1);
    ck_assert_int_eq(datum_vergleichen(b, a), 1);

}
END_TEST

START_TEST(datum_ausgabe_zweistellig)
{
#line 29
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

}
END_TEST

START_TEST(datum_ausgabe_einstellig)
{
#line 44
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
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, datum_ist_gleich);
    tcase_add_test(tc1_1, datum_ist_davor);
    tcase_add_test(tc1_1, datum_ist_danach);
    tcase_add_test(tc1_1, datum_ist_davor_gleicher_monat_gleiches_jahr);
    tcase_add_test(tc1_1, datum_ausgabe_zweistellig);
    tcase_add_test(tc1_1, datum_ausgabe_einstellig);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
