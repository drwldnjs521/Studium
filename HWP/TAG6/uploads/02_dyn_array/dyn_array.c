#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dyn_array.h"

void print_array(dyn_array* arr) {
    int i;

    printf("**** Arraystatus ****\n");
    printf("Länge: %i\n", arr->length);
    printf("Füllstand: %i\n", arr->fill_level);

    for(i = 0; i < arr->fill_level; i++) {
        printf("[%i]: %s\n", i, arr->strings[i]);
    }
}


/* Implementieren Sie hier die restlichen Funktionen. */




