#include<stdio.h>
#include<stdlib.h>

struct array{ int wert[3];};

struct array init_array(void) {
	int i;
	struct array z;
	
	for(i = 0; i < sizeof(struct array) / sizeof(int); i++) {
		printf("Wert %d eingeben: ", i);
		scanf("%d", &z.wert[i]);
	}
	return z;
}

void output_array(struct array z) {
	int i;
	
	for(i = 0; i < sizeof(struct array) / sizeof(int); i++) 
		printf("%d\t", z.wert[i]);
	printf("\n");
}

int main(void) {
	struct array new_array;
	
	new_array = init_array();
	output_array(new_array);
	return EXIT_SUCCESS;
}
