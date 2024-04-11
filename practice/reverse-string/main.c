#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void flushKey(void);

int main(void) {
	char name[31];
	char address[51];
	char reverse[51];
	
	printf("Please enter your name: ");
	scanf("%30[^\n]", &name);
	flushKey();
	
	printf("Please enter address: ");
	scanf("%30[^\n]", &address);
	flushKey();
	
	printf("name: %s\n", name);
	printf("address: %s\n", address);

	strcpy(reverse, _strrev(name));
	printf("reversed: %s\n", reverse);
	return 0;
}

void flushKey(void) {
	char ch;
	do {
		ch = getchar();
	} while (ch != '\n');
}