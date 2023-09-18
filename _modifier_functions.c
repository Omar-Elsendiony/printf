#include "main.h"


void copyChars(char *dest, char *src, int *destReachedIndex)
{
    int i = 0;
    while (src[i] != '\0' && src[i] != '.')
    {
        dest[(*destReachedIndex)++] = src[i];
        i++;
    }
}


int getNumber(char *numArr)
{
    int val = 0, i = 0;

    while (numArr[i] != '\0')
    {
        val *= 10;
        val += (numArr[i] - '0');
        i++;
    }
    return (val);
}

char *modifierProcessingDecimal(int sizeDecimal, char *width,char *numChars, char *precision, int sFlag,int negNum)
{
    int widthNum, numDecimalDigits = 0, numIntegerDigits = 0, i = 0;
    int precisionNum = 0, diff1, sizeFinalString = 0, reachedIndex = 0  + (sFlag || negNum);
    char *finalString;

    
    if (floatChars[i++] == '.')
        numDecimalDigits = getNumber(floatChars + i);

    if (widthBeforeDP != NULL)
    {
        widthNum = getNumber(widthBeforeDP);
    }
    if (precision != NULL)
    {
        precisionNum = getNumber(precision);
        diff1 = numDecimalDigits - precisionNum;
        numDecimalDigits -= diff1;
    }
}



char *modifierProcessingFloat(char *widthBeforeDP,char *floatChars, char *precision, int sFlag,int negNum)
{
    int widthNum, numDecimalDigits = 0, numIntegerDigits = 0, i = 0;
    int precisionNum = 0, diff1, sizeFinalString = 0, reachedIndex = 0  + (sFlag || negNum);
    char *finalString;

    while(floatChars[i] != '\0' && floatChars[i] != '.')
    {
        numIntegerDigits++;
        i++;
    }
    if (floatChars[i++] == '.')
        numDecimalDigits = getNumber(floatChars + i);

    if (widthBeforeDP != NULL)
    {
        widthNum = getNumber(widthBeforeDP);
    }
    if (precision != NULL)
    {
        precisionNum = getNumber(precision);
        diff1 = numDecimalDigits - precisionNum;
        numDecimalDigits -= diff1;
    }
    sizeFinalString = (widthNum > numIntegerDigits + 1 + numDecimalDigits)? widthNum : numIntegerDigits + 1 + numDecimalDigits;
    finalString = malloc(sizeFinalString + 1 + (sFlag || negNum));
    if (sFlag && !negNum)
        finalString[0] = '+';
    if (negNum)
        finalString[0] = '-';
    copyChars(finalString, floatChars, &(reachedIndex));
    finalString[reachedIndex++] = '.';
    copyChars(finalString, floatChars + i, &reachedIndex);
    
    while (sizeFinalString - reachedIndex > 0)
    {
        finalString[reachedIndex++] = '0';
    }
    finalString[reachedIndex] = '\0';
    return (finalString);
}


/*
 *btt
 *@pflag : plus flag
 *@mflag : minus flag
 *@spaceflag : plus flag
*/
char **modifierParsing(char *modifier, int *pFlag, int *mFlag, int *sFlag, int *zFlag, char **arr)
{
    int i = 0, widthLength = 0, widthStartPosition = 0, precisionStartPosition = 0, k = 0, l = 0, precisionLength = 0;
    /* widthBeforeDP  -- the width before the decimal point*/
    char *width = NULL;
    /* widthAfterDP  -- the width after the decimal point*/
    char *precision = NULL;
    i = 0;
    while(modifier[i] != '\0')
    {
        if (modifier[i] == '+')
            *pFlag = 1;
        else if(modifier[i] == '-')
            *mFlag = 1;
        else if(modifier[i] == ' ')
            *sFlag = 1;
        else if(modifier[i] == '0')
            *zFlag = 1;
        else if (modifier[i] >= '1' && modifier[i] <= '9')
        {
            widthStartPosition = i;
            while(modifier[i] >= '0' && modifier[i] <= '9')
            {
                widthLength++;
                i++;
            }
            width = malloc(widthLength + 1);
            for (k = widthStartPosition; k < i; k++)
            {
                width[l++] = modifier[k];
            }
            width[l] = '\0';
            if (modifier[i] == '.')
            {
                i++;
                precisionStartPosition = i;
                while (modifier[i] >= '0' && modifier[i] <= '9')
                {
                    precisionLength++;
                    i++;
                }
                precision = malloc(precisionLength + 1);
                l = 0;
                for (k = precisionStartPosition; k < i; k++)
                {
                    precision[l++] = modifier[k];
                }
                precision[l] = '\0';
            }
        }
        i++;
    }
    arr[0] = width;
    arr[1] = precision;
    return arr;
}

int canBeModifier(int test)
{
    if ((test >= '0' && test <= '9') || test == '+' || test == '-' || test == '.')
        return 1;
    return 0;
}
