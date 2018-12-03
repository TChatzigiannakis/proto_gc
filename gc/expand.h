#include "common.h"

void GC_expand(void)
{
    GC_resize(GC_capacity * 2);
}