#include "main.h"
/* #include<stdio.h> */
#include <string.h>

int _printf(const char *format, ...)
{
	va_list valist;
	int bufferIndex, formatIndex, countChar;
	char *returnedCharArr;
	char buffer[1024] = {0};
	char arr[64] = {0};
	char modarr[32] = {0};
	/* float temp; */
	if (format == ((void *) 0))
		return (-1);
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
                    if (format[formatIndex + 1] == '%')
                        insertToBufferChar(format[formatIndex++], buffer, &bufferIndex, &countChar);
					else
                    {
                        if (returnedCharArr == NULL)
                        {
                            insertToBufferChar('%', buffer, &bufferIndex, &countChar);
                        }
                        else
                            insertToBufferCharP(returnedCharArr, buffer, &bufferIndex, &countChar);
                        break;
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

/*
int main(void)
{
	int dec = 223;
	float fraction = 3.264;
	char character = 'a';
	char *str = "hello world";
	int count_our_printf;
	int count_std_printf;
	count_our_printf = _printf(" %d\n %i\n %u\n  %o\n %x\n %X\n %f\n %c\n %s\n", dec, dec, dec, dec, dec, dec, fraction, character, str);
	count_std_printf = printf(" %d\n %i\n %u\n  %o\n %x\n %X\n %f\n %c\n %s\n", dec, dec, dec, dec, dec, dec, fraction, character, str);
	printf("%d ************ %d\n", count_our_printf, count_std_printf);
	return (0);
}
*/
