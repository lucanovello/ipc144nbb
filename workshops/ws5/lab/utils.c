#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "utils.h"

void flushKey(void) {
	while (getchar() != '\n');
}
void nl(void) {
	putchar('\n');
}
int getInt(void) {
	int inum;
	char newLine = ' ';
	while (scanf("%d%c", &inum, &newLine) != 2 || newLine != '\n') {
		flushKey();
		printf("Bad integer, try again\n> ");
	}
	return inum;
}
float getFlt(void) {
	float fnum;
	char newLine = ' ';
	while (scanf("%f%c", &fnum, &newLine) != 2 || newLine != '\n') {
		flushKey();
		printf("Bad real number, try again\n> ");
	}
	return fnum;
}
double getDbl(void) {
	double dnum;
	char newLine = ' ';
	while (scanf("%lf%c", &dnum, &newLine) != 2 || newLine != '\n') {
		flushKey();
		printf("Bad real number, try again\n> ");
	}
	return dnum;
}
void getLine(char str[]) {
	scanf("%[^\n]", str);
	flushKey();
}
