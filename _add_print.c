#include <unistd.h>
#include "main.h"
void insertToBufferChar(char c, char *buffer, int *pBufferIndex, int *pCountChar)
{
	buffer[*(pBufferIndex)] = c;
	++*(pBufferIndex);
	++*(pCountChar);
	if (*pBufferIndex == BUFFER_SIZE)
	{
		printBuffer(buffer, BUFFER_SIZE);
    }
}

void printBuffer(char *buffer, int size)
{
	write(1, buffer, size);
}
