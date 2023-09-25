#include "main.h"
#include <stdio.h>

int main(void)
{
	int len, len2;

	len = _printf("%");
	len2 = printf("%");
	fflush(stdout);
	if (len != len2)
	{
        printf("%d\n", len);
        printf("%d\n", len2);
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}