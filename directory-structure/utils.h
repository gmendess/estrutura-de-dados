#ifndef _DIRECTORY_STRUCTURE_UTILS_H
#define _DIRECTORY_STRUCTURE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include "directory_structure.h"

#define CHECK_IF_NULL(pointer) do {                     \
  if(pointer == NULL) {                                 \
    fprintf(stderr, "Malloc fail at %s()\n", __func__); \
    exit(1);                                            \
  }                                                     \
} while(0)


#endif // _DIRECTORY_STRUCTURE_UTILS_H