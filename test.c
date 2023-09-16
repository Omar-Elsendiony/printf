#include <string.h>
#include <stdarg.h>
#include <stdio.h>


int main(void)
{
    float f = 6.6;
    int l = 0;
    int m;
    m = (int) f;
    while ((int)f - f != 0)
    {
        f *= 10;
        l++;
    }
    printf("%d", m);
    return (0);
}
