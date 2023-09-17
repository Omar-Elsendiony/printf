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
				if (formatIndex != 0 && format[formatIndex - 1] != '\\')
				{
					returnedCharArr = getSpecifier(&formatIndex, format, arr, &valist, modarr);
					insertToBufferCharP(returnedCharArr, buffer, &bufferIndex, &countChar);
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
	int x = 4561;
	int hx = 4561;
	char *lolo = "polymethyl";
	char *m = "hello";
	int count;
	count = _printf("\n**%f**\n%o\n%x/n %s", f, x, hx, m);
	printf("\n%d\n\n", count);
	return (0);
}
