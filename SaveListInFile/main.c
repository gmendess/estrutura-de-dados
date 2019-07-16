#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "linked_list.h"

int main(const int argc, const char** argv) {

  List* list = createList();
  if(!list) {
    fprintf(stderr, "Ocorreu um erro ao criar a lista!\n");
    return EXIT_FAILURE;
  }  

  addNode(list, "Olá mundo!");
  addNode(list, "AAA doidera!");
  addNode(list, "Teste!");
  addNode(list, "Teste2!");
  addNode(list, "Teste3!");
  addNode(list, "Teste4!");
  
  puts("-----");
  printList(list);

  pop(list);

  puts("-----");
  printList(list);

  return 0;
}
