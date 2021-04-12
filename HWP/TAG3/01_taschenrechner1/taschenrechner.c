/* taschenrechner.c */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char *argv[]) {

	char ch;
	int wert = 0;
	int zahl = 0;
	
	while((ch = getopt(argc, argv, "p:m:h")) != EOF) {
		switch(ch) {
			case 'p':
				wert += atoi(optarg);
				break;
			case 'm':
				wert -= atoi(optarg);
				break;
			case 'h':
				printf("\t Option : \n");
				printf("\t-p : \"Plus\"\n");
				printf("\t-m : \"Minus\"\n");
				printf("\t-h : print Hilfe page\n");
				break;
			default: 
				break;	
		}
	}
		
	argc -= optind;
	argv += optind;
		
	for(zahl = 0; zahl < argc; zahl++) {
		if((strcmp(argv[zahl], "Ente")) == 0) { 
			printf("HEIß, HEIß, HEIß\n");
			return 0;
		}
		wert += atoi(argv[zahl]);
	}
		
	
	printf("%d\n", wert);
	
	return 0;
	
}
		
		
				
