#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
void insertToBufferChar(char c, char *buffer, int *pBufferIndex, int *pCountChar);
void insertToBufferCharP(char *subString, char *buffer, int *pBufferIndex, int *pCoutChar);
void printBuffer(char *buffer, int *pBufferIndex, int size);
void printTillEmpty(char *buffer);
void getSpecifier(int *pFormatIndex, const char *format,char *arr, va_list valist);
void convertFromFloat(char *arr, float f);
#endif
