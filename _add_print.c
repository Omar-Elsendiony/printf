#include <unistd.h>
#include "main.h"
void insertToBufferChar(char c, char *buffer, int *pBufferIndex, int *pCountChar)
{
	buffer[*(pBufferIndex)] = c;
	++*(pBufferIndex);
	++*(pCountChar);
	if (*pBufferIndex == BUFFER_SIZE)
	{
		printBuffer(buffer, pBufferIndex, BUFFER_SIZE);
	}
}

void insertToBufferCharP(char *subString, char *buffer, int *pBufferIndex, int *pCoutChar)
{
	int i;

	for (i = 0; subString[i]; ++i)
	{
		buffer[*(pBufferIndex)] = subString[i];
		++*(pBufferIndex);
		if (*pBufferIndex == BUFFER_SIZE)
		{
			printBuffer(buffer, pBufferIndex, BUFFER_SIZE);
		}
	}
}

void printBuffer(char *buffer, int *pBufferIndex, int size)
{
	write(1, buffer, size);
	*pBufferIndex = 0;
}
