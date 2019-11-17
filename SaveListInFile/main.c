#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "util.h"
#include "linked_list.h"

/*
  Compile com:
  gcc main.c util.c linked_list.c -o main
*/

int main() {

  List* list = createList();
  assert(list != NULL);

  FILE* file = openFile();
  assert(file != NULL);

  /* TESTE PARA EXPORTAR LISTA
  push(list, "Primeiro nó da lista!");
  push(list, "Mensagem qualquer :)");
  push(list, "AAAA BBBB CCCC");
  printList(list);
  
  if(exportList(file, list) == SUCCESS)
    puts("Lista exportada com sucesso para o arquivo!");
  else
    puts("Falha ao exportar lista!");
  */

  /* TESTE PARA IMPORTAR LISTA
  printList(list); // primeiro print, lista vazia
  if(importList(file, list) == SUCCESS) {
    puts("Dados importados com sucesso para a lista!");
    printList(list);
  }
  else
    puts("Falha ao importar dados para a lista!");
  */

  deleteList(&list);
  fclose(file);

  return 0;
}
