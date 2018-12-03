#include "common.h"

GC_ALLOC_INFO *GC_next(void)
{
    return &GC_allocations[GC_object_count++];
}