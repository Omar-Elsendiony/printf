#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

int getSpecifier(int *pBufferIndex,int *pFormatIndex, char *format, char *buffer,char *arr)
{
    //incrementing before going on
    ++(*pFormatIndex);
    char *modifier;
    switch(format[*pFormatIndex])
    {
        case('f'):
            // if ()
        case('c'):

        default:
            ++(*pFormatIndex);
    }

}

int _printf(const char *format, ...)
{
	va_list valist;
    int bufferIndex, formatIndex, countChars;
    char buffer[1024] = {0};
    char arr[64] = {0};
    if (format == NULL)
        return (1);
    va_start(valist, format);
    while (format[formatIndex] != '\0')
    {

        switch(format[formatIndex])
        {
            case('%'):
                if (i != 0 && format[i] != '\\')
                    getSpecifier(&bufferIndex, &formatIndex, format, buffer);
            case('\\'):
                i++;
                continue;
            default:
                insertIntoBuffer(buffer, );
        }
        ++(bufferIndex);
        ++(formatIndex);
    }
    int temp = va_arg(valist, int);
    char temp2 = va_arg(valist, int);
    printf("%d %c\n", temp, temp2);

}


int main(void)
{
    int x = 0x30;
    char df = 'a';
    int a[] = {0, 0, 0};
    _printf("%s", x, df);
}
