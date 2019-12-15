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

File* create_file(const char* name, const size_t file_size) {
  File* file = (File*) malloc(sizeof(File));
  CHECK_IF_NULL(file);

  file->name = (char*) name;
  file->size = file_size;
  file->next = NULL;

  return file;
}