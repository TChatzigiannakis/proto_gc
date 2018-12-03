#include <memory.h>

#include "common.h"

void GC_compact(void)
{
    size_t target = 0;
    size_t alive = 0;
    for (size_t i = 0; i < GC_object_count; i++)
    {
        GC_ALLOC_INFO *info = &GC_allocations[i];
        if (info->alive)
        {
            alive++;
            target = i;
        }
        else
        {
            memcpy(&GC_allocations[target], info, sizeof(GC_ALLOC_INFO));
            target++;
        }
    }
    GC_object_count = alive;
}