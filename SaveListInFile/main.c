#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "util.h"
#include "linked_list.h"

int main() {

  List* list = createList();
  if(!list) {
    fprintf(stderr, "Ocorreu um erro ao criar a lista!\n");
    return EXIT_FAILURE;
  }  

  FILE* file = openFile();

  char buffer[20];
  for(int x = 0; x < 20; x++){
    sprintf(buffer, "no numero %d", x);
    addNode(list, buffer);
  }

  for(int x = 5; x < 15; x++)
    removeNode(list, x);


  exportList(file, list);

  printList(list);

  deleteList(&list);
  fclose(file);

  return 0;
}
