#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

List* createList() {
  
  List* list = (List*) malloc( sizeof(List) );
  if(list != NULL) {
    list->size = 0;
    list->head = NULL;
    list->end = NULL;
  }

  return list; // depois do retorno no código cliente, verificar se a list é NULL
}

Node* createNode() {

  Node* new_node = (Node*) malloc( sizeof(Node) );
  if(new_node != NULL) { 
    new_node->id = -1;
    new_node->next = NULL;
  }

  return new_node; // depois do retorno, verificar se new_node é NULL
}

Node* findNode(const List* const list, const int id) {
  if(list == NULL) return NULL; // lista nula
  if(list->head == NULL) return NULL; // lista vazia
  if(id < 0 || id > list->end->id) return NULL; // id menor que zero ou maior que o maior id da lista

  Node* aux = list->head;
  while(aux != NULL && aux->id != id)
    aux = aux->next;

  return aux; // atenção, aux pode ser NULL, verificar antes de sair usando >:[
}

// target_id = ID do nó alvo, logo essa função retornaria o nó anterior a ele
Node* prevNode(const List* const list, const int target_id) {
  if(list == NULL) return NULL; // lista nula
  if(list->head == NULL) return NULL; // lista vazia
  if(target_id <= 0 || target_id > list->end->id) return NULL; // id menor ou igual a zero ou maior que o maior id da lista

  Node* aux = list->head;
  while(aux != NULL && aux->next->id != target_id)
    aux = aux->next;

  return aux; // atenção, aux pode ser NULL, verificar antes de sair usando >:[
}



int addNode(List* const list, const char* msg) {
  if(list == NULL)
    return NULL_LIST;

  Node* new_node = createNode();
  if(new_node == NULL)
    return CREATE_NODE_FAIL;

  new_node->id = list->curr_id;
  strcpy(new_node->buffer, msg);
  
  if(list->head == NULL){
    list->head = new_node;
    list->end = new_node;
  }  
  else if (list->curr_id == list->size) { // significa que o node será colocado no final da lista
    list->end->next = new_node;
    list->end = new_node;
  }
  else { // node vai ser colocado na posição curr_id da lista
    //pegando o node anterior da posição que eu quero colocar meu novo node
    Node* aux = prevNode(list, list->curr_id);
    if(aux == NULL)
      return SEARCH_NODE_FAIL;
    
    new_node->next = aux->next;
    aux->next = new_node;
  }
  
  ++list->size;
  list->curr_id = list->size;

  return SUCCESS;
}

int pop(List* const list) {
  if(list == NULL)
    return NULL_LIST;
  else if(list->head == NULL)
    return EMPTY_LIST;

  list->curr_id = list->end->id;
  Node* prev = prevNode(list, list->end->id);
  
  free(list->end);

  // Não existe nó prev, ou seja, só há 1 nó na lista
  if(prev == NULL) {
    list->head = NULL;
    list->end = NULL;
  } 
  else {
    prev->next = NULL;
    list->end = prev;  
  }

  --list->size;

  return SUCCESS;
}

int removeNode(List* const list, const int id) {
  if(list == NULL)
    return NULL_LIST;
  else if(list->head == NULL)
    return EMPTY_LIST;
  else if(id < 0 || id > list->end->id) // id menor que zero ou maior que o maior id da lista
    return INVALID_ID;

  Node* aux = list->head;
  Node* prev = NULL;

  while(aux != NULL && id != aux->id){
    prev = aux;
    aux = aux->next;
  }

  // Nó não encontrado
  if(aux == NULL)
    return SEARCH_NODE_FAIL;
  else if(aux == list->head)
    list->head = aux->next;
  else if(aux == list->end)
    list->end = prev;
  else
    prev->next = aux->next; // prev só é NULL se aux == list->head, logo não tem necessidade de verificação

  list->curr_id = id; // ID do próximo nó será o do nó recém excluído
  --list->size;

  if(prev != NULL && (list->size == 1 || aux == list->end) )
    list->end = prev;

  free(aux);
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