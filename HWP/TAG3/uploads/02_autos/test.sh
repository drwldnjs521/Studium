#!/usr/bin/env bash

name="autos"
ausgaben=(
    neuer_als_2015.txt
    weniger_als_100000km.txt
    bezeichnung_bus1.txt
    bus1_dateiausgabe.txt
)

# Kompilieren
gcc "$name.c" -o "$name" -Wall -std=c99 -g

# Ausgaben erzeugen.
mkdir -p ausgaben
"./$name" -g 2015 < $name.txt > ausgaben/neuer_als_2015.txt
"./$name" -k 100000 < $name.txt > ausgaben/weniger_als_100000km.txt
"./$name" -b Bus1 < $name.txt > ausgaben/bezeichnung_bus1.txt
"./$name" -b Bus1 ausgaben/bus1_dateiausgabe.txt < $name.txt

# Ausgaben vergleichen.
for ausgabe in ${ausgaben[*]} ; do
    if diff ausgaben/$ausgabe erwartete_ausgaben/$ausgabe ; then
        echo -e "OK: \"ausgabe/$ausgabe\" stimmt mit erwarteter Ausgabe überein."
    else
        echo -e "FEHLER: \"ausgabe/$ausgabe\" stimmt nicht mit der erwarteten Ausgabe \"erwartete_ausgabe/$ausgabe\" überein:"
        diff -y ausgaben/$ausgabe erwartete_ausgaben/$ausgabe
        exit 1
    fi
done

rm -f autos
rm -rf ausgaben
