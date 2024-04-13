#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "utils.h"


void reverseString(void) {
	char name[31];
	char address[51];
	char reverse[51];

	printf("Please enter your name: ");
	scanf("%30[^\n]", &name);
	flushKey();

	printf("Please enter address: ");
	scanf("%50[^\n]", &address);
	flushKey();

	strcpy(reverse, _strrev(name));

	printf("name: %16s\n", name);
	printf("address: %16s\n", address);
	printf("reversed: %16s\n", reverse);
}