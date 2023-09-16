#include "main.h"
#include <string.h>

int _printf(const char *format, ...)
{
	va_list valist;
	int bufferIndex, formatIndex, countChar;
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
				if (formatIndex != 0 && format[formatIndex] != '\\')
				{
					getSpecifier(&formatIndex, format, buffer, valist);
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
				countChar++;
		}
		++(formatIndex);
	}
	printTillEmpty(buffer);
	return (countChar);
}


int main(void)
{
	int f = 0x30;
	_printf("sss%f", f);
	return (0);
}
