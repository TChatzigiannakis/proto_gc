#include "gc/init.h"
#include "gc/full.h"
#include "gc/resize.h"
#include "gc/expand.h"
#include "gc/next.h"
#include "gc/collect.h"
#include "gc/malloc.h"
#include "gc/calloc.h"
#include "gc/free.h"

#define malloc GC_malloc
#define calloc GC_calloc
#define free GC_free