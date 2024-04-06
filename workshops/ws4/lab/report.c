#include <stdio.h>
#include "utils.h"
#include "report.h"


void readStudentInfo(int stno[], float mark[], int num) {
	int i;
	printf("Enter %d student records:", num);
	nl();
	for (i = 0; i < num; i++)
	{
	printf("Enter Student Information # %d:", i+1);
	nl();
	printf("Student Number\n> ");
	stno[i] = getInt();
	printf("Mark\n> ");
	mark[i] = getFlt();
	printf("----------------------");
	nl();
	}
}

void printReport(const int stno[], const float mark[], int num) {
	int i;
	float totalMarks = 0;
	float avg = 0;
	printf("student number   mark");
	nl();
	printf("---------------+------");
	nl();
	for (i = 0; i < num; i++)
	{
		printf("%d         |  %.1f", stno[i], mark[i]);
		nl();
		totalMarks += mark[i];
	}
	avg = totalMarks / num;
	printf("---------------+------");
	nl();
	printf("       Average:   %.1f", avg);
	nl();
}