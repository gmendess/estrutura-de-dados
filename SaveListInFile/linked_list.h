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
  int curr_id; // armazena o ID do próximo nó a ser adicionado
  Node* end; // ponteiro pro último node. Fica mais fácil de acessar o final da lista
  Node* head; // ponteiro pro primeiro node
}List;

List* createList();
Node* createNode();
int addNode(List* const list, const char* msg);
Node* findNode(const List* const list, const int id);

// Essa função é parecida com a findNode, a diferença é que findNode retorna NULL caso não encontre o nó desejado,
// logo, se eu usar ela para pegar o nó anterior com base no ID de um nó, talvez ela me retorne NULL, pois
// não posso assumir que os IDs são consecutivos, ou seja, se eu quiser pegar o nó anterior ao nó de ID 5, eu teria 
// que pegar o nó de ID 4, porém a lista pode estar dessa forma: 0 -> 1 -> 2 -> 5
// Nela o nó 4 não existe, e findNode me retornaria NULL, já prevNode, retornaria o nó 2 
// meudeus que explicação 
Node* prevNode(const List* const list, const int target_id); // deve ser usada apenas internamente


int printList(const List* const list);
int pop(List* const list);
int removeNode(List* const list, const int id);

#endif