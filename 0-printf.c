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
                		if (formatIndex == 0 || (formatIndex != 0 && format[i] != '\\'))
                    			getSpecifier(&bufferIndex, &formatIndex, format, buffer);
				break;
            		default:
                		insertToBufferChar(format[formatIndex], buffer, &bufferIndex, &countChars);
        	}
        	++(formatIndex);
	}
	return contChars;
}
