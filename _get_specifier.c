#include "main.h"

int canBeModifier(int test)
{
    if ((test >= '0' && test <= '9') || test == '+' || test == '-' || test == '.' || test == '#' || test == 'l' || test == 'h')
        return 1;
    return 0;
}


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

char *reverseStr(char * s)
{
    int i;
    int len = strLen(s);
    char *revStr = malloc(len + 1);
    if (!revStr)
        return ((void *) 0);
    for (i = 0; i < len; ++i)
    {
        revStr[i] = s[len - i - 1];
    }
    revStr[len] = '\0';
    return (revStr);
}

char *rotStr(char *s)
{
    int i;
    int len = strLen(s);
    char *rot = malloc(len + 1);
    if (!rot)
        return (0L);
    for (i = 0; s[i]; ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            rot[i] = (((s[i] - 'a') + 13) % 26) + 'a';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            rot[i] = (((s[i] - 'A') + 13) % 26) + 'A';
        }
        else
        {
            rot[i] = s[i];
        }
    }
    rot[i] = s[i];
    return (rot);
}

char *getSpecifier(int *pFormatIndex, const char *format,char *arr, va_list *valist, char *modfierString, char *mallocFlag, char *charflag)
{
    /*int startingIndex;
    char *modifier;*/
    char * s;
    int i = 0;
    ++(*pFormatIndex);
    /* if the string format ends with %*/
    if (format[*pFormatIndex] == '\0')
    {
        --(*pFormatIndex);
        arr[0] = 0;
        return (arr);
    }
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
                *charflag = 1;
                return (arr);
            case('s'):
                s = va_arg(*valist, char *);
                if (s == NULL)
                    s = "(null)";
                return (s);
            case('r'):
                *mallocFlag = 1;
                s = va_arg(*valist, char *);
                s = reverseStr(s);
                return (s);
            case('R'):
                *mallocFlag = 1;
                 s = va_arg(*valist, char *);
                 s = rotStr(s);
                 return (s);
            default:
                if (!canBeModifier(format[*pFormatIndex]))
                {
                    --(*pFormatIndex);
                    return ('\0');
                }
                modfierString[i] = format[*pFormatIndex];
                ++i;              
        }
        ++(*pFormatIndex);
    }
    return (arr);
}
