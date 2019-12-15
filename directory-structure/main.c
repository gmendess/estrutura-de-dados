#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "directory_structure.h"

int main(int argc, char* argv[]) {

  Directory* new_directory = create_directory("teste");
  assert(new_directory != NULL);
  assert(new_directory->name != NULL);
  assert(strcmp(new_directory->name, "teste") == 0);
  assert(new_directory->files == NULL);
  assert(new_directory->sub_dirs == NULL);

  File* new_file = create_file("arquivo.txt", 12);
  assert(new_file != NULL);
  assert(new_file->name != NULL);
  assert(strcmp(new_file->name, "arquivo.txt") == 0);
  assert(new_file->size == 12);
  assert(new_file->next == NULL);

  return EXIT_SUCCESS;
}
