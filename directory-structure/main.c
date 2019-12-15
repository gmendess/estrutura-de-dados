#include <stdlib.h>
#include <stdio.h>
#include "directory_structure.h"

int main(int argc, char* argv[]) {

  Directory* new_directory = create_directory("teste");
  puts(new_directory->name);

  return EXIT_SUCCESS;
}
