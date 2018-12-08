#ifndef _LIST_PROTOTYPES_H
#define _LIST_PROTOTYPES_H

#include <stdlib.h>
#include <stdio.h>

//Struct responsável por representar o conteúdo que cada nó armazena
typedef struct datanode{
   char nome[30]; //string de 29 caracteres + \0
   int id; //id do nó
}DataNode;

//Struct responsável por representar cada nó
typedef struct node{
   DataNode data; //conteúdo que o nó armazena
   struct node* next; //ponteiro para o próximo nó
}Node;

//Struct responsável por representar a lista
typedef struct list{
   int size; //quantidade de nós presentes na lista
   Node* head; //nó cabeça, que aponta para o primeiro nó da lista
}List;

//Função que cria a lista e inicializa seus valores
List* create_list();

//Função que adiciona um nó no final da lista
void append(List* list, DataNode data);
//Função que adiciona um nó na posição passada
void insert(List* list, DataNode data, const int index);

//Imprime o conteúdo de todos os nós da lista
void printList(List* list);

//Retorna a posição do nó passado
int indexOf(List* list, const Node* const node);

//Retorna o nó contido na posição passada
Node* atPos(List* list, const int index);

//Função que exclui um nó da lista com base na posição passada
void pop(List* list, const int index);
//Função que limpa exclui todos os nós da lista
void clear(List *list);
//Função que deleta a lista
void delList(List *list);

//Função que troca dois nós de posição
void swapNodes(List* list, Node* nodeA, Node* nodeB);

//Funções que ordem a lista em ordem crescente e decescente, respectivamente
void ascSort(List* list);
void descSort(List* list);

//Funções que retornam o node que possuia menor e maior ID, respectivamente
Node* min(List* list, const int index);
Node* max(List* list, const int index);

#endif