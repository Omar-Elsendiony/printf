#ifndef MAIN_H_
#define MAIN_H_
#define BUFFER_SIZE 1024
void insertToBufferChar(char c, char *buffer, int *pBufferIndex, int *pCountChar);
void insertToBufferCharP(char *subString, char *buffer, int *pBufferIndex, int *pCoutChar);
void printBuffer(char *buffer, int *pBufferIndex, int size);
void reInitArr(char *array, size);
void reverseArr (char *arr, int size);
void converIntToStr(char *arr, int num, int size);
#endif
