#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

void _printf(char *a)
{
	printf("%p", a);

}


int main(void)
{

    char a[] = {0, 0, 0};
    _printf(a);
    return (0);
}
