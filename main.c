#include "main.h"
#include <stdio.h>

int main(void)
{
<<<<<<< HEAD
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
=======
    int c = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
>>>>>>> 3d4d311ffe2e1ecf61607b137211585456e581cf
    printf("\n%d\n", c);

    /*_printf("%+-05d\n", 26);
     printf("%+-5d\n", 26);

    _printf("%05d\n", 26);
    printf("%05d\n", 26);

    _printf("%0+5d\n", 26);
     printf("%0+5d\n", 26);*/
    
    return 0;
}
