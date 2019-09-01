#include <stdlib.h>
#include <stdio.h>
#include "lmsc.h"

int main() {

  FILE* file = fopen("example.lms", "r");
  LMS* lms = createLMS();
  Table* table = createTable();

  readInstructions(lms, table, file);

  return EXIT_SUCCESS;
}