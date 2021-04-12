/* count_all.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * In diesem Array sollen Sie jedes im Text enthaltene Token einmal speichern
 * Wir gehen davon aus, dass der Text maximal 80 Token mit je maximal 80 Zeichen
 * enthaelt. Ausnahmsweise verwenden wir eine globale Variable.
 */
char tokens[80][81];

/*
 * extract_and_count soll die Token aus dem Eingabestring "source" im globalen
 * Array "tokens" speichern, die Anzahl der verschiedenen Token zurueckgeben
 * und im übergebenen Array "count" speichern, wie oft jedes Token im
 * Eingabestring enthalten ist, wobei die Indizes der beiden Arrays "count"
 * und "tokens" korrespondieren, d.h. count[i] und tokens[i] beschreiben das
 * gleiche Token.
 */
 


int extract_and_count(char *source,  int *count) {
	
	int unterschiedliche_tokens = 0, num = 0, flag = 1;
	int i, j, k= 0;
	char tmp[80][81];
	char *ptr;
	ptr = strtok(source, ".,!? ");
	while(ptr != NULL) {
		strcpy(tmp[num] , ptr);
		num++;
		ptr = strtok(NULL, ".,!? ");
	}
    
    for(i = 0; i < num; i++) {
        for(j = 0; j < i; j++) {
            if(strcmp(tmp[i], tmp[j]) == 0) {
                flag = 0; 
            }
        }
        if(flag) {
            unterschiedliche_tokens++;
            strcpy(tokens[k], tmp[i]);
            k++;
		}
        flag = 1;
    }
    
    for(i = 0; i < unterschiedliche_tokens; i++) {
		count[i] = 0;
		for(j = 0; j < num; j++) {
			if(strcmp(tokens[i], tmp[j]) == 0)
				count[i]++;
		}
	}
    
    return unterschiedliche_tokens;
}
/*
 * Die Funktion print soll jedes Token des Textes genau einmal mit der 
 * zugehoerigen Häufigkeit ausgeben und wird nicht mittels Unittests getestet.
 */

void print(int diff_tokens, int *count) {
	
	for(int i = 0; i < diff_tokens; i++) 
		printf("%d.Token: %s\n Häufigkeit: %d\n", i+1, tokens[i], count[i]);
	
}
/*
 * Es ist wahrscheinlich hilfreich, weitere Funktionen zu schreiben!
 */

