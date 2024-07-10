#ifndef __SHALLOC_H
#define __SHALLOC_H
#include <stdio.h>

void *heap_alloc(size_t bytes);
void heap_free(void *addr);

#endif
