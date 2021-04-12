/*
Der folgende Befehl kompiliert die Datei "hello.c" zu einer ausführbaren
Datei mit Namen "hello".

    gcc -Wall -std=c99 hello.c -o hello

Die erzeugte Datei kann dann ausgeführt werden mit dem Befehl:

    ./hello

*/

#include <stdio.h>

int main(){
    printf("Hello, World!\n");

    return 0;
}
