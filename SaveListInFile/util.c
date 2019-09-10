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
// Nota: ele reabre o arquivo em modo wb para apagar o conteúdo antes de exportar os nós
int exportList(FILE* file, const List* const list) {
  if(list == NULL)
    return EMPTY_LIST;
  if(file == NULL)
    return NULL_FILE;

  //só muda o modo do stream para escrita (também apaga o conteúdo antigo)
  freopen(NULL, "wb+", file);

  Node* aux = list->head;
  size_t bytes = 0; // usado para guardar a quantidade de bytes gravados no arquivos
  while(aux != NULL) {
    bytes = fwrite(aux, sizeof(Node), 1, file);    
    aux = aux->next;
  }
  return SUCCESS;
}

int importList(FILE* file, List* const list) {
  if(list == NULL)
    return EMPTY_LIST;
  if(file == NULL)
    return NULL_FILE;

  fseek(file, 0, SEEK_END); // movendo indicador de posição para o final do arquivo
  size_t file_size = ftell(file); // pegando tamanho do arquivo em bytes
  rewind(file); // retornado indicador de posição para o inicio do arquivo

  // arquivo vazio ou os bytes não correspondem com uma sequência de nós valida
  if(file_size == 0 || file_size % sizeof(Node) != 0) 
    return INVALID_FILE;

  Node* new_node = createNode();
  if(new_node == NULL) //verificando se alocação ocorreu com sucesso
    return CREATE_NODE_FAIL; // retorna código de erro

  fread(new_node, sizeof(Node), 1, file);
  
  list->head = new_node;
  Node* aux = list->head; // nó auxiliar de list->head, ele que percorrerá a lista linkando cada nó no próximo

  #define ever (;;)
  for ever { // KKKKKKKKKKKKKKK, meodeos, genial isso
    new_node = createNode(); // aloca memória para outro nó e retorna o ptr para new_node
    if(new_node == NULL) //verificando se alocação ocorreu com sucesso
      return CREATE_NODE_FAIL; // retorna código de erro
    
    // lê alguns sizeof(Node) bytes do arquivo binário e preenche new_node com esses bytes
    fread(new_node, sizeof(Node), 1, file); 
    
    //verificando fim do arquivo binário
    if(feof(file)) {
      free(new_node); //liberando memória recém alocada
      aux->next = NULL; // encerrando a lista, último nó aponta para NULL
      break; // encerra loop infinito
    }
    else {    
      aux->next = new_node; // linka um nó ao nó recém adicionado
      aux = aux->next; // vai para o próximo, e recém adicionado, nó
    }
  }

  return SUCCESS;
}
