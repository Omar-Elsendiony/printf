#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
int _putchar(char c);
void insertToBufferChar(char c, char *buffer, int *pBufferIndex, int *pCountChar);
void insertToBufferCharP(char *subString, char *buffer, int *pBufferIndex, int *pCoutChar);
void printBuffer(char *buffer, int *pBufferIndex, int size);
void printTillEmpty(char *buffer);
char *getSpecifier(int *pFormatIndex, const char *format,char *arr, va_list *valist, char *modfierString);
int convertFromFloat(char *arr, float f, int negNum);
void insertIntoModifier(char *mod, const char *format, int startingIndex, int lastIndex);
char **modifierParsing(char *modifier, int *pFlag, int *mFlag, int *sFlag, int *zFlag, char **arr);
char *modifierProcessingFloat(char *widthBeforeDP,char *floatChars, char *precision, int sFlag,int negNum);
int canBeModifier(int test);
int decimalToString(char *str, int num, int base, int negNum);
char *getEscapeChar(char inChar);
char *modifierProcessingDecimal(int sizeDecimal, char *numChars, char *width, char *precision, int pFlag, int mFlag, int sFlag, int negNum);

#endif
