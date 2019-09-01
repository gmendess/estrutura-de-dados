#include <stdlib.h>
#include <stdio.h>
#include "simpletron.h"

int main() {

  Simpletron* simpletron = createSimpletron();
  loadInstructions(simpletron);
  run(simpletron);
  //memoryDump(simpletron);

  free(simpletron);


  return EXIT_SUCCESS;
}
