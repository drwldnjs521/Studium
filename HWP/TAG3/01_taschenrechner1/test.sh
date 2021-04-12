#!/usr/bin/env bash

# Kompilieren.
gcc taschenrechner.c -o taschenrechner -Wall -std=c99 -g

echo -e "Prüfe Taschenrechner"

echo -e "\nTest ohne Parameter"
output=$(./taschenrechner)
if [ $output == "0" ]; then
    echo -e "\tOK: Ausgabe ist 0."
else
    echo -e "\tFEHLER: Ausgabe sollte 0 sein, ist aber stattdessen $output."
    exit 1
fi

echo -e "\nAddiere 10"
output=$(./taschenrechner -p 10)
if [ $output == "10" ]; then
    echo -e "\tOK: Ausgabe ist 10."
else
    echo -e "\tFEHLER: Ausgabe sollte 10 sein, ist aber stattdessen $output."
    exit 1
fi

echo -e "\nAddiere 20, subtrahiere 5"
output=$(./taschenrechner -p 20 -m 5)
if [ $output == "15" ]; then
    echo -e "\tOK: Ausgabe ist 15."
else
    echo -e "\tFEHLER: Ausgabe sollte 15 sein, ist aber stattdessen $output."
    exit 1
fi

echo -e "\nUnbenutzte Parameter 1, 10 und 100 sollen aufaddiert werden."
output=$(./taschenrechner 1 10 100)
if [ $output == "111" ]; then
    echo -e "\tOK: Ausgabe ist 111."
else
    echo -e "\tFEHLER: Ausgabe sollte 111 sein, ist aber stattdessen $output."
    exit 1
fi

echo -e "\nZeige Hilfe an"
output=$( ./taschenrechner -h )
if echo -e "$output" | grep -iqw hilfe ; then
    echo -e "\tOK: Hilfe wird angezeigt."
else
    echo -e "\tFEHLER: Ausgabe ($output) enthält nicht das Wort \"Hilfe\"."
    exit 1
fi
