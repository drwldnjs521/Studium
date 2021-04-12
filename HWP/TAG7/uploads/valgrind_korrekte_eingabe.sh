#!/usr/bin/env bash

# Für mehr Informationen zu valgrind:
# https://valgrind.org/docs/manual/mc-manual.html

program="./tetrominos"

echo -e "\n###\n### Teil 1: Korrekte Aufrufe \n###\n"

mkdir -p valgrind

outputfile="valgrind/temporary_output.txt"

for size in 0 5 10 20 50 100 150 200
do
    inputfile="eingabe/$size.txt"
    logfile="valgrind/$size.txt"
    echo -e "Prüfe $inputfile"
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$logfile $program $inputfile $outputfile
    result=$?
    if [ $result -eq 0 ]; then
        echo -e "\tOK: Rückgabewert ist 0."
    else
        echo -e "\tFEHLER: Rückgabewert ist nicht 0, sondern $result."
        exit 1
    fi

    if grep -E "definitely lost: [1-9][0-9,]* bytes" $logfile ; then
        echo -e -e "\tFEHLER: Speicherleck gefunden. Details in Datei $logfile."
        exit 2
    else
        echo -e "\tOK: Speichertest 1"
    fi

    if grep -E "indirectly lost: [1-9][0-9,]* bytes" $logfile ; then
        echo -e "\tFEHLER: Speicherleck gefunden. Details in Datei $logfile."
        exit 2
    else
        echo -e "\tOK: Speichertest 2"
    fi

    if grep -E "possibly lost: [1-9][0-9,]* bytes" $logfile ; then
        echo -e "\tFEHLER: Speicherleck gefunden. Details in Datei $logfile."
        exit 2
    else
        echo -e "\tOK: Speichertest 3"
    fi

    if grep -E "still reachable: [1-9][0-9,]* bytes" $logfile ; then
        echo -e "\tFEHLER: Speicherleck gefunden. Details in Datei $logfile."
        exit 2
    else
        echo -e "\tOK: Speichertest 4"
    fi

    if grep -E "in use at exit: [1-9][0-9,]* bytes" $logfile ; then
        echo -e "\tFEHLER: Speicherleck gefunden. Details in Datei $logfile."
        exit 2
    else
        echo -e "\tOK: Speichertest 5"
    fi

    if grep -E "Invalid free()" $logfile ; then
        echo -e "\tFEHLER: Invalid free gefunden. Details in Datei $logfile."
        exit 2
    else
        echo -e "\tOK: Invalid free test"
    fi

    if grep -E "Invalid read of size" $logfile ; then
        echo -e "\tFEHLER: Invalid read gefunden. Details in Datei $logfile."
        exit 2
    else
        echo -e "\tOK: Invalid read test"
    fi

    if grep -E "Invalid write of size" $logfile ; then
        echo -e "\tFEHLER: Invalid write gefunden. Details in Datei $logfile."
        exit 2
    else
        echo -e "\tOK: Invalid write test"
    fi

    if grep -E "depends on uninitialised value(s)" $logfile ; then
        echo -e "\tFEHLER: Uninitialisierte Variablen verwendet. Details in Datei $logfile."
        exit 2
    else
        echo -e "\tOK: Nur initialisierte Variablen verwendet"
    fi

    echo -e ""

    rm $outputfile
done
