#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "quiz8.h"

int main(void) {
	int guess;
	int results;

	printf("Please enter an integer: ");

	guess = getInt();
	results = quiz8(guess);

	results == 1 ? printf("Success") : printf("Fail");
	nl();

	return 0;
}

