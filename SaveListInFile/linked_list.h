#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#define     MBUFFER_SIZE  50

// valores de retorno
#define          SUCCESS  1
#define        NULL_LIST  0
#define CREATE_NODE_FAIL -1
#define SEARCH_NODE_FAIL -2
#define       EMPTY_LIST -3
#define    INVALID_INDEX -4

typedef struct node{
  short id; // identificador. Vai ser usado pra armazenar o node na posição correta do arq binário
  char buffer[MBUFFER_SIZE]; // pra armazenar uma mensagem qualquer
  struct node* next;
}Node;

typedef struct list{
  size_t size; // quantidade de nodes
  short curr_id; // armazena o ID do próximo nó a ser adicionado
  Node* end; // ponteiro pro último node. Fica mais fácil de acessar o final da lista
  Node* head; // ponteiro pro primeiro node
}List;

List* createList();
Node* createNode();
int addNode(List* const list, const char* msg);
Node* findNode(const List* const list, const int index);
void printList(const List* const list);
int pop(List* const list);
int removeNode(List* const list, const int index);

#endif