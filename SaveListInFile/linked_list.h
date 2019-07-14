#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#define MBUFFER_SIZE 50

typedef struct node{
  short id; // identificador. Vai ser usado pra armazenar o node na posição correta do arq binário
  char buffer[MBUFFER_SIZE]; // pra armazenar uma mensagem qualquer
  struct node* next;
}Node;

typedef struct list{
  size_t size; // quantidade de nodes
  size_t curr_id; // armazena o ID do próximo nó a ser adicionado
  Node* end; // ponteiro pro último node. Fica mais fácil de acessar o final da lista
  Node* head; // ponteiro pro primeiro node
}List;

List* createList();
Node* createNode();
int addNode(List* const list, const char* msg);
Node* findNode(const List* const list, const int index);
void printList(const List* const list);
void pop(List* const list); 

#endif