#!/usr/bin/env bash

gcc main.c autos.c datum.c -std=c99 -Wall -g -o main

./main < autos_eingabe.txt > autos_ausgabe.txt

if diff autos_ausgabe.txt autos_erwartete_ausgabe.txt ;then
    echo -e "OK: Ausgabe ist wie erwartet."
else
    echo -e "FEHLER: Ausgaben unterscheiden sich:"
    diff autos_ausgabe.txt autos_erwartete_ausgabe.txt
    exit 1
fi

rm -f autos_ausgabe.txt main
