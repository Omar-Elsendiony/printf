#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
int _putchar(char c);
int _printf(const char *format, ...);
void insertToBufferChar(char c, char *buffer, int *pBufferIndex, int *pCountChar);
void insertToBufferCharP(char *subString, char *buffer, int *pBufferIndex, int *pCoutChar);
void printBuffer(char *buffer, int *pBufferIndex, int size);
char *getSpecifier(int *pFormatIndex, const char *format,char *arr, va_list *valist, char *modfierString, char *mallocFlag, char *charflag);
void convertFromFloat(char *arr, float f);
void upperCase(char *arr);
int unsignedDecimalToString(char *str, unsigned int num, int base);
void handleMinDecimalToStr(char *arr, int num, int base);
int _printf(const char *format, ...);
void reInit(char *arr, int size);
int getNumber(int val, char num);
int strLen(char *str);
char * modifierProcessing(char *arr, char *modarr);
char *processing(char *arr, int size, int diff, int pflag, int mflag, int sflag, int zflag);
void cpStr (char *src, char *des);
int canBeModifier(int test);
char *reverseStr(char * s);
char *rotStr(char *s);
#endif
