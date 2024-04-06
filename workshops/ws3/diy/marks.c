/*
Luca Novello
gnovello@myseneca.ca
038515003
02-13-2024
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "utils.h"

void prnGrade(char letterGrade)
{
	if (letterGrade == '+')
	{
		printf("A+");
	}
	else
	{
		putchar(letterGrade);
	}
};
char grade(int markOutOf100)
{
	char result='X';

	if (markOutOf100 >= 0 && markOutOf100 <= 49)
	{
		result = 'F';
	}
	else if (markOutOf100 >= 50 && markOutOf100 <= 59)
	{
		result = 'D';
	}
	else if (markOutOf100 >= 60 && markOutOf100 <= 69)
	{
		result = 'C';
	}
	else if (markOutOf100 >= 70 && markOutOf100 <= 79)
	{
		result = 'B';
	}
	else if (markOutOf100 >= 80 && markOutOf100 <= 89)
	{
		result = 'A';
	}
	else if (markOutOf100 >= 90 && markOutOf100 <= 100)
	{
		result = '+';
	}
	return result;
};
int getNoOfStudents(void)
{
	int noOfStudents;
	printf("Please enter the number of students\n> ");
	noOfStudents = getInt();
	if (noOfStudents < 5)
	{
		printf("Minimum number of students is 5!\n");
		noOfStudents = 0;
	}
	if (noOfStudents > 35)
	{
		printf("Maximum number of students is 35!\n");
		noOfStudents = 0;
	}
		return noOfStudents;
};
int getMark(int maximumAcceptableMarkValue)
{
	int studentMark;
	int finalMark;
	printf("Please print a mark between 0 and %d:\n> ", maximumAcceptableMarkValue);
	studentMark = getInt();
	if (studentMark >= 0 && studentMark <= maximumAcceptableMarkValue)
	{
		finalMark = (studentMark * 100) / maximumAcceptableMarkValue;
	}
	else
	{
		finalMark = -1;
		printf("Invalid Mark!\n");
	}
	return finalMark;
};

