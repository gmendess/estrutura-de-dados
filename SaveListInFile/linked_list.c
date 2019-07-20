#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

List* createList() {
  
  List* list = (List*) calloc(1, sizeof(List));
  if(list != NULL) {
    list->size = 0;
    list->head = NULL;
  }

  return list; // depois do retorno no código cliente, verificar se a list é NULL
}

Node* createNode() {

  Node* new_node = (Node*) calloc(1, sizeof(Node));
  if(new_node != NULL) { 
    new_node->id = -1;
    new_node->next = NULL;
    new_node->buffer[0] = '\0';
  }

  return new_node; // depois do retorno, verificar se new_node é NULL
}

Node* findNode(const List* const list, const int id) {
  return NULL;
}

Node* prevNode(const List* const list, const int target_id) {
  return NULL;
}


// adiciona um novo nó no final ou até achar um "buraco" na lista 
int addNode(List* const list, const char* msg) {
  if(list == NULL)
    return NULL_LIST;

  Node* new_node = createNode(); // retornando um nó 'vazio'
  if(new_node == NULL)
    return CREATE_NODE_FAIL;
  
  strncpy(new_node->buffer, msg, sizeof(new_node->buffer)); // copiando para o buffer do nó, a mensagem passada como argumento
  if(list->head == NULL){ // verificando se a lista é vazia
    list->head = new_node;
    new_node->id = 0;
  }
  else{ // se não for, percorre a lista em busca do último nó, ou até encontrar um 'buraco'
    /* Explicação: um 'buraco' é quando a lista perde seu padrão de IDs, exemplo: 0 -> 1 -> 2 -> 4 -> 5
       note que o nó após o 2 é o 4, logo há um buraco onde deveria estar o nó 3 */
    
    Node* aux = list->head; // nó auxiliar para percorrer a lista
    while(aux->next != NULL && aux->next->id == aux->id + 1) // essa última condição verifica um buraco na lista
      aux = aux->next;

    new_node->next = aux->next;
    new_node->id = aux->id + 1;
    aux->next = new_node;
  }
  ++list->size;

  return SUCCESS;
}

// exclui último nó da lista
int pop(List* const list) {
  if(list == NULL)
    return NULL_LIST;
  else if(list->head == NULL)
    return EMPTY_LIST;

  // ponteiros auxiliares
  Node* aux = list->head;
  Node* prev = NULL;

  // percorre a lista até o último nó
  while(aux->next != NULL){
    prev = aux;
    aux = aux->next;
  }

  if(aux == list->head) // se aux == list->head, lista só tem um nó (assim vc pode assumir que prev ainda é NULL)
    list->head = NULL;
  else //a lista tem + de 2 elementos, então prev existe e seu next deve apontar para aux->next, que provavelmente será NULL
    prev->next = aux->next; // ou prev->next = NULL

  free(aux);
  aux = NULL;
  --list->size;

  return SUCCESS;
}

// remove um nó que possui determinado `id`
int removeNode(List* const list, const int id) {
  if(list == NULL)
    return NULL_LIST;
  else if(list->head == NULL)
    return EMPTY_LIST;
  else if(id < 0)
    return INVALID_ID;

  // ponteiros auxiliares
  Node* aux = list->head;
  Node* prev = NULL;

  // percorre até achar um nó com o `id` desejado ou até que aux seja NULL (nó não encontrado)
  while(aux != NULL && aux->id != id){
    prev = aux;
    aux = aux->next;
  }

  if(aux == NULL) // nó com `id` solicitado não existe
    return SEARCH_NODE_FAIL;
  else if(aux == list->head) // nó desejado é o primeiro da lista
    list->head = list->head->next;
  else
    prev->next = aux->next; // nó está em qualquer outra posição, incluindo a última

  free(aux);
  aux = NULL;
  --list->size;

  return SUCCESS;
}

int printList(const List* const list) {
  if(list == NULL) {
    fprintf(stderr, "Lista nula!\n");
    return NULL_LIST;
  }
  else if(list->head == NULL) {
    fprintf(stderr, "Lista vazia!\n");
    return EMPTY_LIST;
  }

  Node* aux = list->head;
  while(aux != NULL){
    printf("%d | %s\n", aux->id, aux->buffer);
    aux = aux->next;
  }

  return SUCCESS;
}
