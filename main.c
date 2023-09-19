#include "main.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    _printf("%5d\n", 26);
    printf("%05d\n", 26); 

    /*_printf("%+-05d\n", 26);
     printf("%+-5d\n", 26);

    _printf("%05d\n", 26);
    printf("%05d\n", 26);

    _printf("%0+5d\n", 26);
     printf("%0+5d\n", 26);*/
    
    return 0;
}