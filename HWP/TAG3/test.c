/* taschenrechner.c */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
 
int main(int argc, char* argv[]){    
    int wert=10;    
    char opt;   
 
    while( (opt = getopt(argc, argv, "a:b:c")) != EOF) {
        switch(opt){            
            case 'a': 
                wert*= atoi(optarg);                
                break;            
            case 'b':
                wert+= atoi(optarg);                
                break;
            case 'c': 
                wert/=2;
                break;
            default:
                fprintf(stderr, "Option unbekannt");
        }
    }
 
    argc-= optind;
    argv+= optind;
 
    printf("%d\n", wert - atoi(argv[1]));
    return 0;
}
