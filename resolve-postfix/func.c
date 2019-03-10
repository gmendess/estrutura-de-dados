#ifndef _FUNC_C
#define _FUNC_C

#include <stdlib.h>
#include "proto.h"

Stack* createStack(){
   Stack* s = (Stack*) malloc(sizeof(Stack));
   if(s == NULL){
      printf("Não foi possível alocar memória para a pilha!\n");
      exit(EXIT_FAILURE);
   }
   return s;
}

Node* createNode(){
   Node* new_node = (Node*) malloc(sizeof(Node));
   if(new_node == NULL){
      printf("Não foi possível alocar memória para o novo nó!\n");
      exit(EXIT_FAILURE);
   } 
   return new_node;
}

void push(Stack* s, int value){
   if(s == NULL) return;
   Node* new_node = createNode();
   new_node->value = value;
   new_node->next = *s;
   *s = new_node;
}

int pop(Stack* s){
   if(s == NULL || *s == NULL) return -1;

   Node* aux = *s;
   const int value = aux->value;
   *s = aux->next;
   free(aux);
   return value;
}

int calculate(const int num1, const int num2, const char op){
   switch(op){
      case '+':
         return num1 + num2;
      case '-':
         return num2 - num1;
      case '*':
         return num1 * num2;
      case '/':
         return (int) num2 / num1;
      case '%':
         return num1 % num2;
      case '^':
         return exponentiation(num1, num2);
   }
}

int exponentiation(int num1, const int num2){
   if(num2 == 0)
      return 1;
   if(num2 == 1)
      return num1;

   return num1 * exponentiation(num1, num2-1);
}

void printStack(const Stack* const s){
   if(s == NULL || *s == NULL) return;

   Node* aux = *s;
   for(; aux != NULL; aux = aux->next)
      printf("%d ", aux->value);
   putchar('\n');
}



#endif
