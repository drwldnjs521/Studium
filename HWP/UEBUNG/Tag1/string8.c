/* string8.c */
#include <stdio.h>
#include <stdlib.h>

const char p[] = {"123xyz456"};

int check_passwort(char passw[]) {
	int i,n = sizeof (p) / sizeof(char);
	
	for(i=0; i < n; i++) {
		if(p[i] != passw[i]) 
			return 0;
	}
	return 1;
}

int main(void) {
	char Name[20], Passwort[10];
	
	printf("Login-Name : ");
	fgets(Name, 20, stdin);
	printf("Passwort : ");
	fgets(Passwort, 10, stdin);
	
	if(check_passwort(Passwort) == 1)
		printf("Willkommen im System %s\n", Name);
	else 
		printf("Falsches Passwort! Systemzugriff verweigert.\n");
	return EXIT_SUCCESS;
}
