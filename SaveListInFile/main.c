#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "util.c"
#include "linked_list.c"

int main() {

  List* list = createList();
  if(!list) {
    fprintf(stderr, "Ocorreu um erro ao criar a lista!\n");
    return EXIT_FAILURE;
  }  

  FILE* file = openFile();
  if(!file) {
    fprintf(stderr, "Ocorreu um erro ao abrir o arquivo!\n");
    return EXIT_FAILURE
  }

  // importando lista armazenada no arquivo binário para minha lista
  importList(file, list);
  
  // imprimindo conteúdo da lista na tela
  printList(list);

  // liberando memória da lista e fechando arquivo
  deleteList(&list);
  fclose(file);

  return 0;
}
