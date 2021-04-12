/* strcmp, strcat, strchr, strlen, strcspn */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void String_Vergleich(char str1[], char str2[]) {
	int ret = strcmp(str1, str2);
	if(ret == 0) {
		printf("%s == %s \n", str1, str2);
	} else {
		printf("%s %c %s\n", str1, ( (ret < 0) ? '<' : '>'), str2);
	}
}

int main(void) {
	char ziel[30] = "HALLO ";
	char name[20];
	char str[] = "Ein String mit Worten";
	char string[] = "Das ist ein Teststring";
	char str1[] = "Ich bin Jeewon";
	char str2[] = "Ich bin Jeehyun";
	char str3[] = "Ich bin Jeehye";
	int pos;
	
	pos = strcspn(string, "Ttg");
	printf("Erstes Auftreten von T, t oder g an Pos.: %d\n",pos);
	
	printf("Wie heissen Sie: ");
	fgets(name, 20, stdin);
	
	strcat(ziel, name);
	printf("%s", ziel);
	printf("%s\n", strchr(str, (int)'W'));
	String_Vergleich(str1, str2);
	String_Vergleich(str1, str3);
	String_Vergleich(str2, str3);
	return EXIT_SUCCESS;
}
