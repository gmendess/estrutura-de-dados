#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

#define          SUCCESS  1
#define        NULL_LIST  0
#define CREATE_NODE_FAIL -1

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

Node* findNode(const List* const list, const int index) {
  Node* aux = list->head;
  while(aux->next != NULL && aux->id != index)
    aux = aux->next;

  return aux;
}


int addNode(List* const list, const char* msg) {
  if(list == NULL){
    fprintf(stderr, "A lista passada é nula!\n");
    return NULL_LIST;
  }

  Node* new_node = createNode();
  if(!new_node) {
    fprintf(stderr, "Falha ao criar novo nó!\n");
    return CREATE_NODE_FAIL;
  }

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
    Node* aux = findNode(list, list->curr_id - 1);
    new_node->next = aux->next;
    aux->next = new_node;

  }
  
  ++list->size;
  list->curr_id = list->size;

  return SUCCESS;
}

void pop(List* const list) {
  if(list == NULL) {
    fprintf(stderr, "List nula!\n");
    return;
  }
  else if(list->head == NULL) {
    puts("Lista vazia!");
    return;
  }

  list->curr_id = list->end->id;
  free(list->end);
  
  if(list->head->next == NULL){
    list->end = NULL;
    list->head = NULL;
  }
  else{
    Node* aux = findNode(list, list->curr_id - 1);
    aux->next = NULL;
    list->end = aux;
  }

  --list->size;
}

void printList(const List* const list) {
  if(list == NULL) {
    fprintf(stderr, "List nula!\n");
    return;
  }
  else if(list->head == NULL) {
    puts("Lista vazia!");
    return;
  }

  Node* aux = list->head;
  while(aux != NULL){
    printf("%d | %s\n", aux->id, aux->buffer);
    aux = aux->next;
  }

}