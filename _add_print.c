#include <unistd.h>

void insertToBuffer(char c, char *buffer, int *pBufferIndex, int *pCountChar)
{
	buffer[i] = c;
	++*(pBufferIndex);
	++*(pCountChar)
	if (*pBufferIndex == BUFFER_SIZE)
	{
		printBuffer(buffer, BUFFER_SIZE);

}

void printfBuffer(char *buffer, int size)
{
	write(1, buffer, size);
}
