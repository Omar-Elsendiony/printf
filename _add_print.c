#include "main.h"

void insertToBufferChar(char c, char *buffer, int *pBufferIndex, int *pCountChar)
{
	buffer[*(pBufferIndex)] = c;
	++*(pBufferIndex);
	++*(pCountChar);
	if (*pBufferIndex == BUFFER_SIZE)
	{
		printBuffer(buffer, pBufferIndex, BUFFER_SIZE);
        buffer[*(pBufferIndex)] = '\0';
	}
    else
        buffer[*(pBufferIndex) + 1] = '\0';
}

void insertToBufferCharP(char *subString, char *buffer, int *pBufferIndex, int *pCountChar)
{
	int i;
    char myNull [] = "(null)";
    if (subString != ((void*) 0))
        for (i = 0; subString[i]; ++i)
        {
            buffer[*(pBufferIndex)] = subString[i];
            ++*(pBufferIndex);
            ++*(pCountChar);
            if (*pBufferIndex == BUFFER_SIZE)
            {
                printBuffer(buffer, pBufferIndex, BUFFER_SIZE);
            }
        }
    else
    {
        for (i = 0; myNull[i] != '\0'; ++i)
        {
            buffer[*(pBufferIndex)] = myNull[i];
            ++*(pBufferIndex);
            ++*(pCountChar);
            if (*pBufferIndex == BUFFER_SIZE)
            {
                printBuffer(buffer, pBufferIndex, BUFFER_SIZE);
            }
        }
    }
}

void printBuffer(char *buffer, int *pBufferIndex, int size)
{
	write(1, buffer, size);
	*pBufferIndex = 0;
}


void upperCase(char *arr)
{
	int i;

	for (i = 0; arr[i]; ++i)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
			arr[i] -= 'a' - 'A';
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
