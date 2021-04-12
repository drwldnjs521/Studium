/* autos.c */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char option;
	int zahl = 0;
	int jahr;
	char auto_name[20];
	int kilometer;
	char *p;
	FILE *ausgabe;
	
	
	if(argc < 2) {
	 while(scanf("%s %d %d", auto_name, &jahr, &kilometer) == 3) 
					fprintf(stdout, "%s %d %d\n", auto_name, jahr, kilometer);
	}else if((argc%2) != 1) {
		ausgabe = fopen(argv[argc-1], "w");
		while((option = getopt(argc, argv, "k:g:b:")) != EOF) {
			switch(option) {
			case 'k':
				zahl = atof(optarg);
				while((scanf("%s %d %d", auto_name, &jahr, &kilometer)) == 3) {
					if(kilometer < zahl) 
						fprintf(ausgabe, "%s %d %d\n", auto_name, jahr, kilometer);
					
				}
				break;
			
			case 'g':
				zahl = atoi(optarg);
				while(scanf("%s %d %d", auto_name, &jahr, &kilometer) == 3) {
					if(jahr > zahl) {
						fprintf(ausgabe, "%s %d %d\n", auto_name, jahr, kilometer);
					}
				}
				break;
			
			case 'b':
				p = optarg;
				while(scanf("%s %d %d", auto_name, &jahr, &kilometer) == 3) {
					if(strcmp(p, auto_name) == 0) {
						fprintf(ausgabe, "%s %d %d\n", auto_name, jahr, kilometer);
					}
				}
				break;
				
		}
	  }
	}else {
	    
	    while((option = getopt(argc, argv, "k:g:b:")) != EOF) {
		switch(option) {
			case 'k':
				zahl = atof(optarg);
				while((scanf("%s %d %d", auto_name, &jahr, &kilometer)) == 3) {
					if(kilometer < zahl) 
						fprintf(stdout, "%s %d %d\n", auto_name, jahr, kilometer);
					
				}
				break;
			
			case 'g':
				zahl = atoi(optarg);
				while(scanf("%s %d %d", auto_name, &jahr, &kilometer) == 3) {
					if(jahr > zahl) {
						fprintf(stdout, "%s %d %d\n", auto_name, jahr, kilometer);
					}
				}
				break;
			
			case 'b':
				p = optarg;
				while(scanf("%s %d %d", auto_name, &jahr, &kilometer) == 3) {
					if(strcmp(p, auto_name) == 0) {
						fprintf(stdout, "%s %d %d\n", auto_name, jahr, kilometer);
					}
				}
				break;
			
				
		}
	}
}
	
	
	argc -= optind;
	argv += optind;
	
	
	return EXIT_SUCCESS;
				
}
