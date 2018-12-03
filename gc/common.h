#ifndef GC_COMMON_H
#define GC_COMMON_H

#include <stdlib.h>

typedef struct GC_ALLOC_INFO_STRUCT
{
    int alive;
    uintptr_t address;
    size_t size;
} GC_ALLOC_INFO;

size_t GC_capacity = 0;
size_t GC_object_count = 0;
GC_ALLOC_INFO *GC_allocations = NULL;

uintptr_t GC_stack_begin = 0;
uintptr_t GC_stack_end = 0;

uintptr_t GC_heap_begin = 0;
uintptr_t GC_heap_end = 0;

void GC_init(void);
int GC_full(void);

void *GC_malloc(size_t);
void *GC_calloc(size_t, size_t);
void GC_free(void *);

#endif