/*
Luca Novello
gnovello@myseneca.ca
038515003
02-13-2024
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "utils.h"
#include "marks.h"

int getMaxGrade(void) {
	int maxGrade;
	printf("What are the marks out of?\n> ");
	maxGrade = getInt();
	return maxGrade;
}

void report(int numberOfStudents) {
	int counter = 0;
	int maxGrade = getMaxGrade();
	int lowestMark = 101;
	int highestMark = -1;
	double totalMarks = 0;
	double averageMark;

	while (counter < numberOfStudents)
	{
		int mark;
		printf("%d- ", counter + 1);
		mark = getMark(maxGrade);

		if (mark >= 0) {
			printf("Entered: %d%%, ", mark);
			prnGrade(grade(mark));
			putchar('\n');
			totalMarks += mark;
			if (mark > highestMark)
			{
				highestMark = mark;
			}
			if (mark < lowestMark)
			{
				lowestMark = mark;
			}
			counter += 1;
		}
	}
	averageMark = totalMarks / numberOfStudents;
	printf("Lowest mark entered: %d\n", lowestMark);
	printf("Highest mark entered: %d\n", highestMark);
	printf("Average of all marks: %.1f%%\n", averageMark);
}


