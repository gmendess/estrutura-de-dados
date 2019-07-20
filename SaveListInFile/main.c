#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "linked_list.c"

int main() {

  List* list = createList();
  if(!list) {
    fprintf(stderr, "Ocorreu um erro ao criar a lista!\n");
    return EXIT_FAILURE;
  }  

  addNode(list, "olá mundo! 0");
  addNode(list, "olá mundo! 1");
  addNode(list, "olá mundo! 2");
  addNode(list, "olá mundo! 3");

  pop(list);
  pop(list);
  pop(list);
  pop(list);

  printList(list);

  // hehe, tinha esquecido
  free(list->head);
  free(list);

  return 0;
}
