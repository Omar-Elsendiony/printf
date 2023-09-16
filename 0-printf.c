#include "main.h"
#include <string.h>

int _printf(const char *format, ...)
{
	va_list valist;
	int bufferIndex, formatIndex, countChar;
	char buffer[1024] = {0};
	char arr[64] = {0};
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
				if (formatIndex != 0 && format[formatIndex] != '\\')
				{
					getSpecifier(&formatIndex, format, arr, &valist);
					insertToBufferCharP(arr, buffer, &bufferIndex, &countChar);
				}
				break;
			case('\\'):
				if (format[formatIndex + 1] == '\\') /* TO BE SEEN YETTTTTT*/
				{
					++(formatIndex);
				}
				break;
			default:
				insertToBufferChar(format[formatIndex], buffer, &bufferIndex, &countChar);
		}
		++(formatIndex);
	}
	printTillEmpty(buffer);
	return (countChar);
}


int main(void)
{
	float f = 5.678;
	float f1 = 5.678;
	float f2 = 5.678;
	_printf("\n**%f**\n", f);
	printf("\n");
	return (0);
}
