#include <stdio.h>
#include <limits.h>
#include <getopt.h>


int main( int argc, char ** argv ){

    printf("Der Datentyp char benötigt %lu Bytes Speicherplatz.\n", sizeof(char));

    char option;
    while((option = getopt(argc, argv, "mM")) !=EOF){
        switch(option){
            case 'm': 
            {
                printf("Die kleinste darstellbare Zahl beträgt dann %i.\n", CHAR_MIN);
                break;
            }
            case 'M': 
            {
                printf("Die größte darstellbare Zahl beträgt dann %i.\n", CHAR_MAX);
                break;
            }
        }
    }

    return 0;

}
