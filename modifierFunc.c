#include "main.h"
void reInit(char *arr, int size)
{
    int i = 0;

    while (i < size)
    {
        arr[i] = 0;
        ++i;
    }
}

int getNumber(int val, char num)
{
    val *= 10;
    val += (num - '0');
    return (val);
}
    
int strLen(char *str)
{
    int i = 0; 
    while (str[i])
        ++i;
    return (i);
}

char *processing(char *arr, int size, int diff, int pflag, int mflag, int sflag, int zflag)
{
    int i = 0;
    char *outputPtr = malloc(size + 1);
    
    if (!outputPtr)
        return (NULL);
    if (zflag && diff && !mflag)
    {
        while (i != diff)
        {
            outputPtr[i] = '0';
            ++i;
        }
    }
    else if (diff && !mflag)
    {
        while (i != diff)
        {
            outputPtr[i] = ' ';
            ++i;
        }
    }
    if (sflag && diff && zflag && arr[0] != '-')
        outputPtr[0] = ' ';
    else if (sflag && diff && !zflag && arr[0] != '-')
        outputPtr[i - 1] = ' ';
    else if (diff && zflag && arr[0] == '-')
        outputPtr[0] = '-';
    else if (diff && !zflag && arr[0] == '-')
        outputPtr[i - 1] = '-';
    if (pflag && diff && zflag && arr[0] != '-')
        outputPtr[0] = '+';
    else if (pflag && diff && !zflag && arr[0] != '-')
        outputPtr[i - 1] = '+';
    else if (diff && zflag && arr[0] == '-')
        outputPtr[0] = '-';
    else if (diff && !zflag && arr[0] == '-')
        outputPtr[i - 1] = '-';
    return (outputPtr);
}




char *modifierProcessing(char *arr, char *modarr)
{
    int size;
    int len = strLen(arr);
    int diff = 0;
    char *outputStr = NULL;
    char pflag = 0, mflag = 0, sflag = 0, zflag = 0;
    int width = 0, percsion = 0;
    int i = 0;   
    while (modarr[i])
    {
        if (modarr[i] == '+')
            pflag = 1;
        if (modarr[i] == '-')
            mflag = 1;
        if (modarr[i] == ' ')
            sflag = 1;
        if (modarr[i] == '0')
            zflag = 1;
        if (modarr[i] > '0' && modarr[i] <= '9')
        {
            while(modarr[i] && modarr[i] != '.' && modarr[i] != 'l' && modarr[i] != 'h')
            {
                width = getNumber(width, modarr[i]);
                ++i;
            }
        }
        if (modarr[i] > '0' && modarr[i] <= '9')
        {
            while(modarr[i]  && modarr[i] != 'l' && modarr[i] != 'h')
            {
                percsion = getNumber(percsion, modarr[i]);
                ++i;
            }
        }
    }
    size = width >= len ? width : len;
    diff = width >= len ? width - len : len - width;

    outputStr = processing(arr, size, diff, pflag, mflag, sflag, zflag);
    return outputStr;
}