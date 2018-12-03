#include "common.h"

void GC_set_stack_boundaries(void)
{
    int a = 0;
    GC_stack_end = (uintptr_t)&a;
}