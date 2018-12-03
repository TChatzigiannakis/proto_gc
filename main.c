#include <stdlib.h>
#include <stdio.h>

#include "gc.h"

#define COUNT 1024

int main(int argc, char **argv)
{
    GC_init();

    int *p[COUNT] = {NULL};
    for (int i = 0; i < COUNT; i++)
    {
        p[i] = malloc(sizeof(int));
        *p[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < COUNT; i++)
    {
        sum += *p[i];
    }
    printf("End: %d\n", sum);

    return 0;
}
