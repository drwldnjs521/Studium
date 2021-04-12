#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main( int argc, char ** argv ){
    if(argc <= 1){
        printf("Usage:  fassungsvermoegen <zahl>\n");
        return 1;
    }
    
    long long int a = atoll(argv[1]);

    printf("  char      : %d\n", (char)a );
    printf("  int       : %d\n", (int)a );
    printf("  double    : %f\n", (double)a );
    
    return 0;
}
