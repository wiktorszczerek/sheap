#include "sheap.h"
#include <stdio.h>

int main(int argc, char **argv) {
  char *derp = heap_alloc(1);
  *derp = 20;

  printf("Debug: %d\n", *derp);

  heap_free(derp);
  return 0;
}
