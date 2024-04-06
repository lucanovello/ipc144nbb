#include <stdio.h>
#include "utils.h"
#include "report.h"

struct Student getStudent(void) {
	struct Student student;
	printf("Name\n> ");
	getLine(student.name);
	printf("Student Number\n> ");
	student.stNo = getInt();
	printf("Mark\n> ");
	student.mark = getFlt();
	return student;
}

void readStudentInfo(struct Student S[], int num) {
	int i;
	printf("Enter %d student records:", num);
	nl();
	for (i = 0; i < num; i++)
	{
	printf("Enter Student Information # %d:", i+1);
	nl();
	S[i] = getStudent();
	printf("----------------------");
	nl();
	}
}

void printStudent(struct Student S) {
        printf("%-30s| %-15d|  %.1f", S.name, S.stNo, S.mark);
}

void printReport(const struct Student S[], int num) {
        int i;
        float totalMarks = 0;
        float avg = 0;
        printf("%-31s%-17s%s", "Name", "student number", "mark");
        nl();
        printf("------------------------------+----------------+------");
        nl();
        for (i = 0; i < num; i++)
        {
                printStudent(S[i]);
                nl();
                totalMarks += S[i].mark;
        }
        avg = totalMarks / num;
        printf("------------------------------+----------------+------");
        nl();
        printf("%47s%7.1f","Average:", avg);
        nl();
}