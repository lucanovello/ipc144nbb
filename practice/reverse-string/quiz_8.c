#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "utils.h"

int quiz8( int num ) {

	int isValid;

	if (num >= 0 && num < 10) {
		printf("the number %d is between 0-9", num);
		nl();
		return 1;
	}
	else if (num < 0) {
		printf("the number %d is less than 0", num);
		nl();
		return -1;
	}
	else {
		printf("the number %d is higher than 9", num);
		nl();
		return 0;
	}

}