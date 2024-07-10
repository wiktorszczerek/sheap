#include "sheap.h"

#define HEAP_SIZE_LIMIT 32

/*
 * Structure: |HEADER|BYTECHUNK|HEADER|BYTECHUNK ...
 * on heap_array[0] there is ALWAYS a header
 * HEADER: |CHUNKSIZE||FREE?|HEADER?|
 */

char heap_array[HEAP_SIZE_LIMIT] = {0}; // 1B chunk
size_t heap_size = 0;

void heap_init() { heap_array[0] = (HEAP_SIZE_LIMIT << 2) | (1 << 1) | 1; }

void *heap_alloc(size_t bytes) {
  // assert or if?
  if (heap_array[0] == 0)
    heap_init();

  if ((heap_size + bytes) > HEAP_SIZE_LIMIT) {
    printf("Allocation error. Not enough space");
    return NULL;
  }
  int index = 0;
  void *ret = NULL;
  do {
    if ((heap_array[index] & (0x1 << 1)) &&
        (bytes <= (heap_array[index] >> 2))) {
      heap_array[index] = ((bytes << 2) | (0 << 1) | 1);
      ret = heap_array + heap_size;
      heap_size += bytes;
      break;
    } else {
      index += (heap_array[index] >> 2);
    }
  } while (index < HEAP_SIZE_LIMIT);

  return ret;
}

void heap_free(void *addr) { *((char *)addr) |= (1 << 1); }
