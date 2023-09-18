#include "main.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    int count = _printf("%i\n", -326);
    int count2 = printf("%i\n", -326);
    printf("%d ***** %d", count, count2);
    return 0;
}