#include "main.h"
#include <stdio.h>

int main(void)
{
    int c = _printf("%c", '\0');
    printf("\n%d\n", c);

    /*_printf("%+-05d\n", 26);
     printf("%+-5d\n", 26);

    _printf("%05d\n", 26);
    printf("%05d\n", 26);

    _printf("%0+5d\n", 26);
     printf("%0+5d\n", 26);*/
    
    return 0;
}
