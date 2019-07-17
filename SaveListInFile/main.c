#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "linked_list.c"

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

  printf("\n\n\n%d --> %d\n", list->head->id, list->head->next->id);
  removeNode(list, 0);
  printf("%d --> %d\n", list->head->id, list->head->next->id);
  removeNode(list, 1);
  printf("%d --> %d\n", list->head->id, list->head->next->id);
  removeNode(list, 2);
  printf("%d --> %d\n", list->head->id, list->head->next->id);
  removeNode(list, 3);
  printf("%d --> %d\n", list->head->id, list->head->next->id);
  removeNode(list, 4);
  printf("%d -->\n", list->head->id);

  printf(" >>> %d\n", list->head->id);
  removeNode(list, 5);


  puts("-----");
  printList(list);

  return 0;
}
