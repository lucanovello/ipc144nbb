#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Luca Novello
// gnovello@myseneca.ca
// 038-515-003
// 01-16-2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

void title(void);
void line(void);
void info(void);
void calcGrades(void);

int main(void) {
	title();
	line();
	info();
	line();
	calcGrades();
	line();

	return 0;
}

void title(void) {
	printf("IPC144 NBB\tWorkshop 1\tPart 2\n");
}

void line(void) {
	printf("------------------------------------------------------------");
	printf("\n");
}

void info(void) {
	printf("Name:\n\tLuca Novello\nEmail:\n\tgnovello@myseneca.ca\n");
}

void calcGrades(void) {
	int n1;
	int n2;
	int n3;
	int avg;

	printf("Enter the marks for the following subjects,\n");
	printf("IPC144: ");
	scanf("%d", &n1);
	printf("ULI101: ");
	scanf("%d", &n2);
	printf("EAC150: ");
	scanf("%d", &n3);

	avg = (n1 + n2 + n3) / 3;

	printf("The average is: %d\n", avg);
}