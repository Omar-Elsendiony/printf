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

int decimalToString(char *str, int num, int base, int negNum)
{
    int i = 0, rem, temp, trailingOnes = 0;
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
    if (negNum)
    {
        if (base == 16)
        {
            trailingOnes = 8 - length;
            for (i = 0; i < trailingOnes; i++)
                str[i++] = 'f';
        }
        else if (base == 8)
        {
            trailingOnes = 10 - length;
            i = 0;
            str[i] = '3';
            for (; i < trailingOnes; i++)
                str[i++] = '7';
        }
        else if (base == 8)
        {
            str[i++] = '-';
        }
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
                    str[length - i - 1 + trailingOnes] = 'a';
                    break;
                case 11:
                    str[length - i - 1 + trailingOnes] = 'b';
                    break;
                case 12:
                    str[length - i - 1 + trailingOnes] = 'c';
                    break;
                case 13:
                    str[length - i - 1 + trailingOnes] = 'd';
                    break;
                case 14:
                    str[length - i - 1 + trailingOnes] = 'e';
                    break;
                case 15:
                    str[length - i - 1 + trailingOnes] = 'f';
                    break;
            }
        }
        else
                str[length - i - 1 + trailingOnes] = rem + '0';
    }
    str[length] = '\0';
    return (length);
}



int convertFromFloat(char *arr, float f, int negNum)
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
            f *= 10.0;
            l++;
        }
        tempInteger = (int) f;
        decimalPart = tempInteger % (power(10, l));
    }
    reachedIndex = decimalToString(arr, integerPart, 10, negNum);
    arr[reachedIndex++] = '.';
    lengthDecimalPart = decimalToString(arr + reachedIndex, decimalPart, 10, negNum);
    arr[reachedIndex + lengthDecimalPart] = '\0';
    return (reachedIndex + lengthDecimalPart);
}



void insertIntoModifier(char *mod, const char *format, int startingIndex, int lastIndex){
    int i, j = 0;
    for (i = startingIndex; i < lastIndex; i++)
    {
        mod[j++] = format[i];
    }
    mod[i] = '\0';
}

char *getSpecifier(int *pFormatIndex, const char *format,char *arr, va_list *valist, char *modifier)
{
    float f;
    int startingIndex, pFlag = 0, sFlag = 0, mFlag = 0, zFlag = 0, negativeNum = 0, tempInt;
    char *temp[2];
    char *width, *precision, *finalString;
    ++(*pFormatIndex);
    startingIndex = *pFormatIndex;
    while (format[*pFormatIndex])
    {
        switch(format[*pFormatIndex])
        {
            case('f'):
                if ((*pFormatIndex) - startingIndex)
                {
                    modifier = malloc((*pFormatIndex) - startingIndex + 1);
                    insertIntoModifier(modifier, format, startingIndex, (*pFormatIndex));
                }
                modifierParsing(modifier, &pFlag, &mFlag, &sFlag, &zFlag, temp);
                printf("\n\n %s %s %d %d %d", temp[1], temp[0], pFlag, zFlag, sFlag);
                f = va_arg(*valist, double);
                if (f < 0.0)
                {
                    negativeNum = 1;
                    f *= -1;
                }
                convertFromFloat(arr, f, negativeNum);
                width = temp[0];
                precision = temp[1];
                finalString = modifierProcessingFloat(width, arr, precision, pFlag, negativeNum);
                printf("\n\n%s\n\n", finalString);
                return (arr);
            case('c'):
                arr[0] = (char)va_arg(*valist, int);
                arr[1] = '\0';
                return (arr);
                break;
            case('d'):
                if ((*pFormatIndex) - startingIndex)
                {
                    modifier = malloc((*pFormatIndex) - startingIndex + 1);
                    insertIntoModifier(modifier, format, startingIndex, (*pFormatIndex));
                }
                tempInt = decimalToString(arr, va_arg(*valist, int), 10, 0);
                modifierParsing(modifier, &pFlag, &mFlag, &sFlag, &zFlag, temp);
                printf("\n\n %s %s %d %d %d", temp[1], temp[0], pFlag, zFlag, sFlag);
                f = va_arg(*valist, double);
                if (tempInt < 0.0)
                {
                    negativeNum = 1;
                    tempInt *= -1;
                }
                width = temp[0];
                precision = temp[1];
                finalString = modifierProcessingDecimal(tempInt, arr, width, precision, pFlag, mFlag, sFlag, zFlag, negativeNum);
                return (finalString);
                break;
            case('s'):
                return (va_arg(*valist, char *));
                break;
            case('o'):
                decimalToString(arr, va_arg(*valist, int), 8, 0);
                return (arr);
            case('x'):
                decimalToString(arr, va_arg(*valist, int), 16, 0);
                return (arr);
            case('%'):
                --(*pFormatIndex);
                return (modifier);
            default:
                if (canBeModifier(format[*pFormatIndex]))
                    break;
                --*pFormatIndex;
                return ('\0');
        }
        ++(*pFormatIndex);
    }
    return (arr);
}
