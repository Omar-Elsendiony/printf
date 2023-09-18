#include "main.h"

char *getEscapeChar(char inChar)
{
    int i = 0;
    char in[]= {'\n', '\t', '%', '\0', '\\'};
    char *out[] = {"\\n", "\\t", "%%", "\\"};
    while (in[i] != '\0')
    {
        if (in[i] == inChar)
            return out[i];
    }
    return NULL;
}
