#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "util.c"
#include "linked_list.c"

int main() {

  List* list = createList();
  assert(list != NULL);

  FILE* file = openFile();
  assert(file != NULL);

  importList(file, list);
  printList(list);

  printf("%X\n", 0b1010);

  deleteList(&list);
  fclose(file);

  return 0;
}
