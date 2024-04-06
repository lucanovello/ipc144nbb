#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "utils.h"


void flushKey(void) {
   char ch = 'x';
   while(ch != '\n') {
      ch = getchar();
   }
}
void flushFile(FILE* fptr) {
    char ch = 0;
    while (ch != '\n') {
        fscanf(fptr, "%c", &ch);
    }
}
int getInt(void) {
   int value;
   int done = 0;
   char newline = 'x';
   while(!done) {
      if(scanf("%d%c", &value, &newline) == 2) {
         if(newline == '\n') {
            done = 1;
         }
         else {
            printf("Please enter only an integer: ");
            flushKey();
         }
      }
      else { // user enterd non integer
         flushKey();
         printf("Invalid Integer, try again: ");
      }
   }
   return value;
}
int getIntMM(int min, int max, const char valueName[]) {
   int value = getInt();
   while(value < min || value > max) {
      printf("[%d<=%s<=%d], retry: ", min, valueName, max);
      value = getInt();
   }
   return value;
}
double getDbl(void) {
   double value;
   int done = 0;
   char newline = 'x';
   while(!done) {
      if(scanf("%lf%c", &value, &newline) == 2) {
         if(newline == '\n') {
            done = 1;
         } else {
            printf("Please enter only a double: ");
            flushKey();
         }
      } else { // user enterd non integer
         flushKey();
         printf("Invalid Double, try again: ");
      }
   }
   return value;
}
double getDblMM(double min, double max, const char valueName[]) {
   double value = getDbl();
   while(value < min || value > max) {
      printf("[%02.lf<=%s<=%.2lf], retry: ", min, valueName, max);
      value = getDbl();
   }
   return value;
}
void nl(void) {
    putchar('\n');
}
void pause(void) {
   printf("Press <ENTER> to continue....");
   flushKey();
}
int yes(void) {
   char resp;
   char newline;
   printf("(Y)es/(N)o: ");
   do {
      scanf("%c%c", &resp, &newline);
      if(newline != '\n') {
         flushKey();
         resp = 'x';
      }
   } while(resp != 'Y' && resp != 'y' && resp != 'n' && resp != 'N' 
               && printf("Only (y) for Yes and (n) for No are acceptable values; retry\n> "));  // lazy evaluation prints the error message
   return (resp == 'Y' || resp == 'y');
}

/* string handling functions: */

void strCpy(char des[], const char src[]) {
    int i;
    for (i = 0; src[i]; i++) {
        des[i] = src[i];
    }
    des[i] = 0;
}
void strnCpy(char des[], const char src[], int len) {
    int i;
    for (i = 0; i < len && src[i]; i++) {
        des[i] = src[i];
    }
    if (i < len) des[i] = 0;
}
int strCmp(const char left[], const char right[]) {
    int i;
    int done = 0;
    for (i = 0; !done && left[i] && right[i]; i++) {
        if (left[i] != right[i]) {
            done = 1;
        }
    }
    return left[i] - right[i];
}

