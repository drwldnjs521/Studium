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

dyn_array* create(){
    
    dyn_array *i = malloc(sizeof(dyn_array));
    i->length = 1;
    i->fill_level = 0;
    i->strings = malloc(sizeof(char*));
    
    return i;
}

void double_array(dyn_array *arr){
    arr->strings = realloc(arr->strings, 2*sizeof(char*)*(arr->length));
    arr->length *= 2;
}

void halve_array(dyn_array *arr){
    if((arr->fill_level <= arr->length/2) && ((arr->length)/2 != 0)){
       arr->strings = realloc(arr->strings, sizeof(char*)*((arr->length)/2));
       arr->length = arr->length / 2;
     }
}

void add_last(dyn_array *arr, char *string){
     arr->fill_level = arr->fill_level + 1;

	if (arr->fill_level > arr->length) {
		double_array(arr);
	}
	arr->strings[arr->fill_level-1] = malloc(sizeof(char*) * (strlen(string) + 1));
	strcpy(arr->strings[arr->fill_level-1], string);
}

void remove_string(dyn_array *arr, char *string){
      for (int i = 0; i < arr->fill_level; i++) {
		if (strcmp(arr->strings[i], string) == 0) {
			free(arr->strings[i]);
			for (int j = i; j < arr->fill_level - 1; j++) {
				arr->strings[j] = arr->strings[j+1];
			}
			arr->fill_level = arr->fill_level - 1;
			halve_array(arr);
		}
	}
}

void free_array(dyn_array *arr){
      for(int i = 0; i < arr->fill_level; i++) {
		free(arr->strings[i]);
	}

	free(arr->strings);
	free(arr);
}


     




