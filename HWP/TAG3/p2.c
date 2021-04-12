/* p2.c */
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char* argv[]){  
    int wert2;  
    scanf("%d", &wert2);  
    printf("%d", wert2*3 + atoi(argv[1])); 
    return 0;
}
