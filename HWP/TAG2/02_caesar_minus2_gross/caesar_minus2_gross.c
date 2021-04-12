/* caesar_minus2_gross.c */
#include <string.h>

void caesar(char *klartext) {
	int i;
	size_t len = strlen(klartext);
	
	for(i = 0; i < len; i++) {
		if(*(klartext + i) == 'A' || *(klartext + i) == 'B') 
			*(klartext + i) += 24;
		else 
			*(klartext + i) = *(klartext + i) - 2;
	}
}


int encode_and_compare(char *clearstring, char *string_to_encode) {
	
	caesar(string_to_encode);
	if(strcmp(clearstring, string_to_encode) == 0)
		return 1;
	else return 0;
}
