#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include "prototypes.h"

List* create_list(){
   List* li = (List*) malloc(sizeof(List));
   if(li){
      li->size = 0;
      li->head = NULL;
      return li;
   }else{
      fprintf(stderr, "Não foi possível alocar memória para a lista!\n");
      exit(1);
   }
}

int add_at_end(List* const li, const int value){
   if(li == NULL)
      return 0;
   
   Node* new_node = (Node*) malloc(sizeof(Node));
   new_node->value = value;
   new_node->next = NULL;
   new_node->prev = NULL;

   if(li->head == NULL)
      li->head = new_node;
   else{
      Node* aux = li->head;
      while(aux->next != NULL)
         aux = aux->next;
      aux->next = new_node;
      new_node->prev = aux;
   }

   ++li->size;
   return 1;
}

int add_at_start(List* const li, const int value){
   if(li == NULL)
      return 0;
   
   Node* new_node = (Node*) malloc(sizeof(Node));
   new_node->prev = NULL;
   new_node->value = value;
   new_node->next = li->head;

   if(li->head != NULL)
      li->head->prev = new_node;
   li->head = new_node;
   ++li->size;
   return 1;
}

int add_ordered(List* const li, const int value){
   if(li == NULL)
      return 0;
   
   Node* new_node = (Node*) malloc(sizeof(Node));
   new_node->value = value;
   new_node->next = NULL;
   new_node->prev = NULL;
   
   if(li->head == NULL)
      li->head = new_node;
   else{
      Node* aux = li->head, *prev = NULL;

      while(aux != NULL && aux->value < value){
         prev = aux;
         aux = aux->next;
      }

      if(aux == li->head){
         li->head->prev = new_node;
         new_node->next = li->head;
         li->head = new_node;
      }else{
         new_node->next = aux;
         new_node->prev = prev;
         prev->next = new_node;
         if(aux != NULL)
            prev = new_node;
      }
   }
}

int remove_at_start(List* const li){
   if(li == NULL || li->head == NULL)
      return 0;

   Node* aux = li->head;
   li->head = aux->next;
   if(aux->next != NULL)
      aux->next->prev = NULL;
   
   free(aux);
   --li->size;
   return 1;
}

int remove_at_end(List* const li){
   if(li == NULL || li->head == NULL)
      return 0;
   
   Node* aux = li->head;
   for(; aux->next != NULL; aux = aux->next);
 
   if(aux == li->head)
      li->head = NULL;
   else
      aux->prev->next = NULL;

   free(aux);
   --li->size;
   return 1;
}

int remove_by_index(List* const li, const int index){
   if(li == NULL || li->head == NULL || index >= li->size || index < 0)
      return 0;

   Node* aux = li->head;

   int x = 0;
   while(aux != NULL && x != index){
      aux = aux->next;
      ++x;
   }

   if(aux == NULL)
      return 0;

   if(aux == li->head)
      li->head = aux->next;
   else
      aux->prev->next = aux->next;

   if(aux->next != NULL)
      aux->next->prev = aux->prev;


   free(aux);
   return 1;
}

void print_list(const List* const li){
   if(li == NULL)
      return;
   
   if(li->head == NULL)
      puts("Lista vazia!");
   else{
      Node* aux = li->head;

      while(1){
         printf("%d", aux->value);
         if(aux->next == NULL){
            puts(" -> NULL");
            break;
         }else{
            printf(" -> ");
            aux = aux->next;
         }
      }
      for(; aux != NULL; aux = aux->prev){
         printf("%d", aux->value);
         if(aux->prev == NULL)
            puts(" -> head");
         else
            printf(" -> ");
      }
   }   
}


#endif

/*

if(li == NULL || li->head == NULL)
      return 0;
   
   Node* aux = li->head;
   while(aux != NULL && aux->value != value){
      aux = aux->next;
   }
   if(aux == NULL)
      return 0;
   else{
      if(aux == li->head)
         li->head = aux->next;
      else{

      }
      free(aux);
      --li->size;
      return 1;
   }

*/