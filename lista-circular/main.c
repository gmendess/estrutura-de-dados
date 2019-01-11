#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
   int value;
   struct node* next;
}Node;

typedef struct list{
   int size;
   Node* head;
}List;

List* createList();
void push(List* const list, const int value);
void printList(const List* const list);
void insert_start(List* const list, const int value);
void insert_sorted(List* const list, const int value);
void pop(List* const list);
void remove_start(List* const list);
void remove_by_index(List* const li, const int index);

int main(){

   List* list = createList();
   insert_sorted(list, 2);
   insert_sorted(list, 3);
   printList(list);
   remove_by_index(list, 0);
   printList(list);

   return EXIT_SUCCESS;
}

void remove_by_index(List* const li, const int index){
   if(li == NULL || li->head == NULL)
      return;

   if(index >= li->size || index < 0)
      return;

   if(li->head == li->head->next){
      free(li->head);
      li->head = NULL;
   }else{
      if(index == 0){
         Node* aux = li->head,
             * final = li->head;
         while(final->next != li->head)
            final = final->next;
         li->head = li->head->next;
         final->next = li->head;
         free(aux); 
      }else{
         Node* current = li->head, *prev = li->head;
         for(int x = 0; x < index && current->next != li->head; x++){
            prev = current;
            current = current->next;
         }
         prev->next = current->next;;
         free(current);
      }
   }
   li->size--;
}

List* createList(){
   List* list = (List*) malloc(sizeof(List));
   if(list){
      list->size = 0;
      list->head = NULL;
   }
   return list;
}

void push(List* const list, const int value){
   if(list == NULL)
      return;
   
   Node* new_node = (Node*) malloc(sizeof(Node));
   new_node->value = value;
   if(list->head == NULL){
      list->head = new_node;
   }else{
      Node* aux = list->head;
      for(; aux->next != list->head; aux = aux->next);
      aux->next = new_node;
   }
   new_node->next = list->head;
   list->size++;
}

void insert_start(List* const list, const int value){
   if(list == NULL)
      return;
   
   Node* new_node = (Node*) malloc(sizeof(Node));
   new_node->value = value;

   if(list->head == NULL){
      list->head = new_node;
      new_node->next = list->head;
   }else{
      Node* aux = list->head, *prev = list->head;
      while(aux != list->head && aux->value < value){
         prev = aux;
         aux = aux->next;
      }
      new_node->next = aux;
      prev->next = new_node;
   }
   list->size++;
}

void printList(const List* const list){
   if(list == NULL)
      return;
   if(list->head == NULL)
      return;

   Node* aux = list->head;
   do{
      printf("%d\n", aux->value);
      aux = aux->next;
   }while(aux != list->head);
   puts("");
}

void insert_sorted(List* const list, const int value){
   if(list == NULL)
      return;

   Node* new_node = (Node*) malloc(sizeof(Node));
   new_node->value = value;
   if(list->head == NULL){
      list->head = new_node;
      new_node->next = list->head;
   }else{
      if(list->head->value > value){
         Node* aux = list->head;
         while(aux->next != list->head)
            aux = aux->next;
         new_node->next = list->head;
         list->head = new_node;
         aux->next = list->head;
      }else{
         Node* current = list->head->next, *prev = list->head;
         while(current != list->head && value > current->value){
            prev = current;
            current = current->next;
         }
         prev->next = new_node;
         new_node->next = current;
         
      }
   }
   list->size++;
}

void pop(List* const list){
   if(list == NULL)
      return;
   if(list->head == NULL)
      return;

   if(list->size == 1){
      free(list->head);
      list->head = NULL;
   }else{
      Node* aux = list->head;
      Node* prev = NULL;
      while(aux->next != list->head){
         prev = aux;
         aux = aux->next;
      }
      prev->next = list->head;
      free(aux);
   }
   list->size--;
}

void remove_start(List* const list){
   if(list == NULL)
      return;
   if(list->head == NULL)
      return;
   
   if(list->size == 1){
      free(list->head);
      list->head = NULL;
   }else{
      Node* final = list->head;
      while(final->next != list->head)
         final = final->next;

      Node* aux = list->head;
      list->head = aux->next;
      free(aux);
      final->next = list->head;
   }
   list->size--;
}


