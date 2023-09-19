#include "main.h"
#include <stdio.h>

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
int unsignedDecimalToString(char *str, unsigned int num, int base)  /*to be discussed*/
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
	    str[length - i - 1] = rem + '0';
        str[length] = '\0';
    }
    return (length);
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
void handleMinDecimalToStr(char *arr, int num, int base)
{
    if (num > 0)
    {
       (decimalToString(arr, num, base));
    }
    else
    {
        num = -num;
        arr[0] = '-';
        (decimalToString(&arr[1], num, base));
    }
}

char *covertFormatStr(char *str)
{
    char *outputStr = NULL;
    char tmp = 0;
    int i = 0;
    int z = 0;
    int size = 0;
    while (str[i])
    {
        if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
        {
            size += 4;
        }
        else
        {
            ++size;
        }
        ++i;
    }
    outputStr = malloc(size + 1);
    if (!outputStr)
        return (NULL);
    i = 0;
    while (str[z])
    {
        tmp = str[z];
        if ((tmp > 0 && tmp < 32) || tmp >= 127)
        {
            outputStr[i++] = '0';
            outputStr[i++] = 'x';
            if (tmp < 16)
            {
                outputStr[i++] = '0';
                decimalToString(&outputStr[i], tmp, 16);
                ++i;
            }
            else
            {
                decimalToString(&outputStr[i], tmp, 16);
                i += 2;
            }
        }
        else
        {
            outputStr[i] = tmp;
            ++i;
        }
        ++z;
    }
    
    return (outputStr);
}

char *getSpecifier(int *pFormatIndex, const char *format,char *arr, va_list *valist, char *modfierString)
{
    int i = 0;
    char *strPtr = NULL;
    ++(*pFormatIndex);
    while (format[*pFormatIndex])
    {
        switch(format[*pFormatIndex])
        {
            case('d'):
            case('i'):
                handleMinDecimalToStr(arr, va_arg(*valist, int), 10);
                return (modifierProcessing(arr, modfierString));
            case('u'):
                unsignedDecimalToString(arr, va_arg(*valist, unsigned int), 10);
                return (arr);
            case('b'):
                unsignedDecimalToString(arr, va_arg(*valist, unsigned int), 2);
                return (arr);
            case('o'):
                decimalToString(arr, va_arg(*valist, int), 8);
                return (arr);
            case('x'):
                decimalToString(arr, va_arg(*valist, int), 16);
                return (arr);
            case('X'):
                decimalToString(arr, va_arg(*valist, int), 16);
                upperCase(arr);
                return (arr);
            case('f'):
                convertFromFloat(arr, va_arg(*valist, double));
                return (arr);
            case('c'):
                arr[0] = (char)va_arg(*valist, int);
                arr[1] = '\0';
                return (arr);
            case('s'):
                return (va_arg(*valist, char *));
            case('S'):
                strPtr = covertFormatStr(va_arg(*valist, char *));
                return (strPtr);
            default:
                modfierString[i] = format[*pFormatIndex];
                ++i;
        }
        ++(*pFormatIndex);

    }
    return (arr);
}
