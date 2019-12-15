#include <stdlib.h>
#include <stdio.h>
#include "directory_structure.h"

int main(int argc, char* argv[]) {

  Directory* new_directory = create_directory("teste");
  puts(new_directory->name);

  File* new_file = create_file("arquivo.txt", 12);
  puts(new_file->name);
  printf("%lu\n", new_file->size);

  return EXIT_SUCCESS;
}
