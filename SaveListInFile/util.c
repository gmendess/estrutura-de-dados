#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "linked_list.h"

FILE* openFile() {
  FILE* file = fopen("list.bin", "rb+");
  if(file == NULL){
    fprintf(stderr, "Algo deu errado ao abrir o arquivo º-º\n");
    exit(OPEN_FAIL);
  }

  return file;
}

// exporta nós de uma lista encadeada para um arquivo binário
int exportList(FILE* file, const List* const list) {
  if(list == NULL)
    return EMPTY_LIST;
  if(file == NULL)
    return NULL_FILE;

  Node* aux = list->head;
  while(aux != NULL) {
    fseek(file, aux->id * sizeof(Node), SEEK_SET);
    fwrite(aux, sizeof(Node), 1, file);
    rewind(file);
    aux = aux->next;
  }

}
