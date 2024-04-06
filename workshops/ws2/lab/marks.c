#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getInt(void);
double getDouble(void);

double calculateAverageMark(void) {
	double markTotal = 0;
	int counter = 0;
	double markValue;
	double average;
	int noOfMarks;

	printf("Please enter the number of marks\n> ");
	noOfMarks = getInt();

	while (counter < noOfMarks) 
	{
		printf("Enter mark #%d\n> ", counter + 1);
		markValue = getDouble();
		markTotal += markValue;
		counter += 1;
	}

	average = markTotal / noOfMarks;
	return average;
}
