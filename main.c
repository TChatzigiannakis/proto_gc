#include <stdlib.h>
#include <stdio.h>

#include "gc.h"

int main(int argc, char **argv)
{
    GC_init();
    printf("Starting...\n");
    for (unsigned short i = -1; i > 0; i--)
    {
        int *p = malloc(sizeof(int));
        *p = i;
        printf(*p == 1 ? ".\n" : "");
    }
    printf("Finished.\n");
    return 0;
}
