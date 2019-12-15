#include <stdlib.h>
#include <stdio.h>
#include "directory_structure.h"
#include "utils.h"

Directory* create_directory(const char* name) {
  Directory* directory = (Directory*) malloc(sizeof(Directory));
  CHECK_IF_NULL(directory);

  directory->name = (char*) name;
  directory->files = NULL;
  directory->next = NULL;
  directory->sub_dirs = NULL;

  return directory;
}