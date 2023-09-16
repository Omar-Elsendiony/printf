#include "main.h"

int decimalToString(char *str, int num)
{
    int i, rem, temp;
    int length;

    temp = num;
    length = 0;
    while (temp != 0)
    {
        length++;
        temp /= 10;
    }
    for (i = 0; i < length; i++)
    {
        rem = num % 10;
        num /= 10;
        str[length - i - 1] = rem + '0';
    }
    str[length] = '\0';
    return (length);
}



void convertFromFloat(char *arr, float f)
{
    int integerPart, decimalPart, l, tempInteger, reachedIndex, lengthDecimalPart;

    integerPart = (int) f;
    while ((int)f - f != 0)
    {
        f *= 10;
        l++;
    }
    tempInteger = (int) f;
    decimalPart = tempInteger % (l * 10);
    reachedIndex = decimalToString(arr, integerPart);
    arr[reachedIndex++] = '.';
    lengthDecimalPart = decimalToString(arr + reachedIndex, decimalPart);
    arr[reachedIndex + lengthDecimalPart] = '\0';
}

/*void modifierProcessing(char *modifier,char *arr)
{
    return;
}*/


void getSpecifier(int *pFormatIndex, const char *format,char *arr, va_list valist)
{
    /*int startingIndex;
    char *modifier;*/

    ++(*pFormatIndex);
    /*startingIndex = *pFormatIndex;*/
    switch(format[*pFormatIndex])
    {
        case('f'):
            /*if ((*pFormatIndex) - startingIndex)
            {
                modifier = malloc((*pFormatIndex) - startingIndex);
            }*/
            convertFromFloat(arr, va_arg(valist, double));
        case('c'):
            break;
        default:
            ++(*pFormatIndex);
    }
}
