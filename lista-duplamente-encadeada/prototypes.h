#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

typedef struct node{
   int value;
   struct node* next;
   struct node* prev;
}Node;

typedef struct list{
   int size;
   Node* head;
}List;

List* create_list();
int add_at_end(List* const li, const int value);
void print_list(const List* const li);
int add_at_start(List* const li, const int value);
int add_ordered(List* const li, const int value);
int remove_at_start(List* const li);
int remove_at_end(List* const li);
int remove_by_index(List* const li, const int value);

#endif