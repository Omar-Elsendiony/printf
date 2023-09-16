#include "main.h"

int power(int base, int exp)
{
    int i, number;

    number = 1;
    for (i = 0; i < exp; i++)
    {
        number *= base;
    }
    return (number);
}

int decimalToString(char *str, int num, int base)
{
    int i, rem, temp;
    int length;

    temp = num;
    length = 0;
    if (num == 0)
    {
        str[0] = '0';
        return (1);
    }
    while (temp != 0)
    {
        length++;
        temp /= base;
    }
    for (i = 0; i < length; i++)
    {
        rem = num % base;
        num /= base;
	if (rem >= 10)
	{
		switch (rem)
		{
			case 10:
				str[length - i - 1] = 'a';
				break;
			case 11:
				str[length - i - 1] = 'b';
				break;
			case 12:
				str[length - i - 1] = 'c';
				break;
			case 13:
				str[length - i - 1] = 'd';
                break;
			case 14:
				str[length - i - 1] = 'e';
				break;
			case 15:
				str[length - i - 1] = 'f';
				break;
		}
	}
	else
        	str[length - i - 1] = rem + '0';
    }
    str[length] = '\0';
    return (length);
}



void convertFromFloat(char *arr, float f)
{
    int integerPart, integerPart2, decimalPart, l, tempInteger, reachedIndex, lengthDecimalPart;
    integerPart = (int) f;
    integerPart2 = (int)(f * 10);
    l = 0;
    if (integerPart2 % 10 == 0)
    {
        decimalPart = 0;
    }
    else
    {
        while ((int)f - f != 0)
        {
            f *= 10;
            l++;
        }
        tempInteger = (int) f;
        decimalPart = tempInteger % (power(10, l));
    }
    reachedIndex = decimalToString(arr, integerPart, 10);
    arr[reachedIndex++] = '.';
    lengthDecimalPart = decimalToString(arr + reachedIndex, decimalPart, 10);
    arr[reachedIndex + lengthDecimalPart] = '\0';
}

/*void modifierProcessing(char *modifier,char *arr)
{
    return;
}*/



char *getSpecifier(int *pFormatIndex, const char *format,char *arr, va_list *valist, char *modfierString)
{
    /*int startingIndex;
    char *modifier;*/
    int i = 0;
    ++(*pFormatIndex);
    /*startingIndex = *pFormatIndex;*/
    while (format[*pFormatIndex])
    {
        switch(format[*pFormatIndex])
        {
            case('f'):
                /*if ((*pFormatIndex) - startingIndex)
                {
                    modifier = malloc((*pFormatIndex) - startingIndex);
                }*/
                convertFromFloat(arr, va_arg(*valist, double));
                return (arr);
            case('c'):
                arr[0] = (char)va_arg(*valist, int);
                arr[1] = '\0';
                return (arr);
                break;
            case('s'):
                return (va_arg(*valist, char *));
                break;
            case('o'):
                decimalToString(arr, va_arg(*valist, int), 8);
                return (arr);
            case('x'):
                decimalToString(arr, va_arg(*valist, int), 16);
                return (arr);
            default:
                modfierString[i] = format[*pFormatIndex];
                ++i;
        }
        ++(*pFormatIndex);

    }
    return (arr);
}
