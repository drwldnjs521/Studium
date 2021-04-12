#include<stdio.h>

int is_little_endian() {
	int a = 0x1234;
	
	if(*((char*)&a) == 0x34)
		return 1;
	else 
		return 0;
}

int main() {
	
	int res = is_little_endian();
	
	if(res)
		printf("\"0x1234 ist 0x34 0x12 - diese Computer benutzt little-endian.\"\n");
	else
		printf("\"0x1234 ist 0x12 0x34 - dieser Computer benutzt big-endian.\"\n");
	
	return 0;
}
