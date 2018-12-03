#include "common.h"

int GC_full(void)
{
    return GC_capacity == GC_next;
}