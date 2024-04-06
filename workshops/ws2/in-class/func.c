#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void horizontalLine40(int numOfSpaces);
void boxCenter(int numOfAstericks, int numOfSpaces);

void name(void) {
	printf("Luca Novello\n");
}

void box(int widthSpaces, int heightSpaces) {
	horizontalLine40(widthSpaces);
	boxCenter(heightSpaces, widthSpaces - 2);
	horizontalLine40(widthSpaces);
}

void horizontalLine40(int numOfSpaces) {
	int counter = 0;
	while (counter < numOfSpaces)
	{
		putchar('*');
		counter += 1;
	};
	printf("\n");
}

void boxCenter(int numOfAstericks, int numOfSpaces) {
	int asterickCounter = 0;
	int spaceCounter = 0;
	while (asterickCounter < numOfAstericks)
	{
		putchar('*');
		while (spaceCounter < numOfSpaces)
		{
			putchar(' ');
			spaceCounter += 1;
		};
		putchar('*');
		printf("\n");
		asterickCounter += 1;
		spaceCounter = 0;
	};
}