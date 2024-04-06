#include <stdio.h>

void horizontalLine(char left, char middle, char right, int width);
void fillBox(char left, char middle, char right, int width, int height);

void rectangle(char leftTop, char top, char topRight,
	char right, char rightButtom, char buttom,
	char buttomLeft, char left, char fill,
	int width, int height) 
{
		horizontalLine(leftTop, top, topRight, width);
		fillBox(left, fill, right, width, height);
		horizontalLine(buttomLeft, buttom, rightButtom, width);
}

void horizontalLine(char left, char middle, char right, int width) 
{
	int counter = 0;
	putchar(left);
	while (counter < (width - 2))
	{
		putchar(middle);
		counter += 1;
	}
	printf("%c\n", right);
}

void fillBox(char left, char middle, char right, int width, int height)
{
	int counter = 0;
	while (counter < (height - 2))
	{
		horizontalLine(left, middle, right, width);
		counter += 1;
	}
}

