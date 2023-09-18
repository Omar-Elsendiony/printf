#include "main.h"
#include <string.h>

int _printf(const char *format, ...)
{
	va_list valist;
	int bufferIndex, formatIndex, countChar;
	char *returnedCharArr;
	char buffer[1024] = {0};
	char arr[64] = {0};
	char modarr[10] = {0};
	/* float temp; */
	if (format == NULL)
		return (1);
	va_start(valist, format);
	formatIndex = 0;
	bufferIndex = 0;
	countChar = 0;
	/*temp = va_arg(valist, double);
	printf("\n*****%f****\n", temp);*/
	while (format[formatIndex] != '\0')
	{
		switch(format[formatIndex])
		{
			case('%'):
                returnedCharArr = getSpecifier(&formatIndex, format, arr, &valist, modarr);
                insertToBufferCharP(returnedCharArr, buffer, &bufferIndex, &countChar);
				break;
			case('\\'):
                insertToBufferChar(format[formatIndex], buffer, &bufferIndex, &countChar);
                ++(formatIndex);
                returnedCharArr = getEscapeChar(format[formatIndex]);
                insertToBufferCharP(returnedCharArr, buffer, &bufferIndex, &countChar);
				break;
			default:
				insertToBufferChar(format[formatIndex], buffer, &bufferIndex, &countChar);
		}
		++(formatIndex);
	}
	printTillEmpty(buffer);
	return (countChar);
}



