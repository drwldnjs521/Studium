#include<stdio.h>
#include<stdlib.h>

char hello1[] = {"Hallo Welt\n"};
char output[] = {"Ich bin lesbar \0 Ich nicht mehr"};
char denzu[] = {"Mich siehst du 0 Mich und die NULL auch"};

int main(void) {
	printf("%s", hello1);
	printf("%s\n", output);
	printf("%s\n", denzu);
	
	return EXIT_SUCCESS;
}
