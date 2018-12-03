#include <stdlib.h>
#include <stdio.h>

#include "gc.h"

#define SLOTS 256
#define COUNT 1024

int main(int argc, char **argv)
{
    GC_init(&argv);

    int *p[SLOTS] = {NULL};
    for (int i = 0; i < COUNT; i++)
    {
        p[i % SLOTS] = malloc(sizeof(int));
        *p[i % SLOTS] = i;
    }

    GC_collect();

    int sum = 0;
    for (int i = 0; i < SLOTS; i++)
    {
        sum += *p[i];
    }
    printf("End: %d\n", sum);

    return 0;
}
