#include <memory.h>
#include <stdio.h>

#include "common.h"

void GC_cleanup(void)
{
    int freed = 0;
    for (size_t i = 0; i < GC_object_count; i++)
    {
        GC_ALLOC_INFO *info = &GC_allocations[i];
        if (!info->alive)
        {
            free((void *)info->address);
            freed++;
        }
    }

    printf("%d objects freed.\n", freed);
}