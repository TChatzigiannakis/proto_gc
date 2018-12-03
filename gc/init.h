#include "common.h"

void GC_init(void)
{
    GC_allocations = (GC_ALLOC_INFO *)calloc(16, sizeof(GC_ALLOC_INFO));
    GC_capacity = 16;
}