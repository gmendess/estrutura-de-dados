#include <stdlib.h>
#include <stdio.h>
#include "lmsc.h"

int main() {

  FILE* file = fopen("example.lms", "r");
  LMS* lms = createLMS();
  Table* table = createTable();

  readInstructions(lms, table, file);

  puts("\nTabela de símbolos:");
  for(int x = 0; x < table->size; x++)
    if(table->vector[x].type != 'L')
      printf("%d %d\n", table->vector[x].locale, table->vector[x].value);

  puts("\nInstruções em LMS:");
  for(int x = 0; x < SIMPLETRON_MEMORY; x++)
    if(lms->instructions[x] != 0)
      printf("%ld\n", lms->instructions[x]);

  return EXIT_SUCCESS;
}