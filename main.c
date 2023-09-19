#include "main.h"
#include <stdio.h>

int main(void)
{
    /*int c = _printf("12345%");
    printf("\n%d\n", c);
    _printf("%S", "hello\nworld\t");
    printf("%05d\n", -26); */

    _printf("%+-05d\n", 26);
     printf("%+-5d\n", 26);

    _printf("%05d\n", 26);
    printf("%05d\n", 26);

    _printf("%0+5d\n", 26);
     printf("%0+5d\n", 26);
    
    return 0;
}
