#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#define     MBUFFER_SIZE  50

// valores de retorno
#define          SUCCESS  1
#define        NULL_LIST  0
#define CREATE_NODE_FAIL -1
#define SEARCH_NODE_FAIL -2
#define       EMPTY_LIST -3
#define       INVALID_ID -4
#define    GENERIC_ERROR -99 // kkkk

typedef struct node{
  int id; // identificador. Vai ser usado pra armazenar o node na posição correta do arq binário
  char buffer[MBUFFER_SIZE]; // pra armazenar uma mensagem qualquer
  struct node* next;
}Node;

typedef struct list{
  size_t size; // quantidade de nodes
  Node* head; // ponteiro pro primeiro node
}List;

// aloca e retorna um ponteiro para uma List alocada na memória
List* createList();

// aloca e retorna um ponteiro para um Node alocado na memória
Node* createNode();

// libera memória de todos os nós da lista e da própria lista
int deleteList(List** listPtr);

// adiciona um novo nó no final ou até achar um "buraco" na lista 
int addNode(List* const list, const char* msg);

// adiciona um nó no final da lista, mesmo que ela possua 'buracos'
int push(List* const list, const char* msg);

Node* findNode(const List* const list, const int id);
Node* prevNode(const List* const list, const int target_id); // deve ser usada apenas internamente

// imprime todos os nós da lista em ordem
int printList(const List* const list);

// remove o último nó da lista
int pop(List* const list);

// remove o nó de determinado `id`
int removeNode(List* const list, const int id);

#endif