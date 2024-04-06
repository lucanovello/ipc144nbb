#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "utils.h"

int getInt(void) {
	int num;
	scanf("%d", &num);
	flushKey();
	return num;
}

double getDouble(void) {
	double num;
	scanf("%lf", &num);
	return num;
}

void flushKey(void) {
	char ch;
	do {
		ch = getchar();
	} while (ch != '\n');
}