#ifndef SENECA_REPORT_H
#define SENECA_REPORT_H

struct Student {
	char name[31]; // to hold the student name up to 30 characters in a Cstring
	int stNo; // to hold the student number
	float mark;  // to hold the mark of the student
};
struct Student getStudent(void);
void readStudentInfo(struct Student S[], int num);
void printStudent(struct Student Student);
void printReport(const struct Student S[], int num);


#endif // !SENECA_REPORT_H
