#include "main.h"
#include <stdio.h>

int main(void)
{
    int len, len2;

	len = _printf("%c", '\0');
	len2 = printf("%c", '\0');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
    printf("\n%d\n", c);

    /*_printf("%+-05d\n", 26);
     printf("%+-5d\n", 26);

    _printf("%05d\n", 26);
    printf("%05d\n", 26);

    _printf("%0+5d\n", 26);
     printf("%0+5d\n", 26);*/
    
    return 0;
}
