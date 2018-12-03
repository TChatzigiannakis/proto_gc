#include "common.h"

void GC_scan(uintptr_t min, uintptr_t max)
{
    for (uintptr_t i = min; i < max; i++)
    {
        uintptr_t ptr = *(uintptr_t *)i;
        GC_ALLOC_INFO *info = GC_resolve_internal(ptr);
        if (info)
        {
            if (!info->alive)
            {
                info->alive = 1;
                if (info->address)
                {
                    GC_scan(info->address, info->address + info->size);
                }
            }
            else
            {
                info->alive = 1;
            }
        }
    }
}