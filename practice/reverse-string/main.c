#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void flushKey(void);

int main(void) {
	char name[31];
	char nickname[31];
	printf("Please enter your name: ");
	scanf("%30[^\n]", &name);
	flushKey();
	printf("Please enter your nickname: ");
	scanf("%30[^\n}", &nickname);
	flushKey();
	printf("Hello %s\n", name);
	printf("Your nickname is %s\n", nickname);
	return 0;
}

void flushKey(void) {
	char ch;
	do {
		ch = getchar();
	} while (ch != '\n');
}