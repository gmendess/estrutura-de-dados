#ifndef _FUNC_H
#define _FUNC_H

#include <stdlib.h>
#include <ctype.h>
#include "proto.h"


Stack* createStack(){
   Stack* s = (Stack*) malloc(sizeof(Stack));
   if(s == NULL){
      printf("Não foi possível alocar memória para a pilha!\n");
      exit(0);
   }
   s->size = 0;
   s->top = NULL;
   return s;
}

Node* createNode(){
   Node* new_node = (Node*) malloc(sizeof(Node));
   if(new_node == NULL){
      printf("Não foi possível alocar memória para o novo nó!\n");
      exit(0);
   }
   return new_node;
}

int push(Stack* s, const char data){
   if(s == NULL) return 0;

   Node* new_node = createNode();
   new_node->character = data;
   new_node->next = s->top;
   s->top = new_node;
   ++s->size;
   return 1;
}

int isEmpty(Stack* s){
   if(s->size > 0)
      return 0;
   return 1;
}

char pop(Stack* s){
   if(s == NULL || s->top == NULL) return 0;
   Node* aux = s->top;
   char return_value = aux->character;
   s->top = aux->next;
   --s->size;
   free(aux);
   return return_value;
}

int verifyPrecedence(const char op1, const char op2){
   const char operators[][4] = {
      {' '},
      {'+', '-'},
      {'*', '/', '%'},
      {'^'},
   };

   int p_op1 = 0, p_op2 = 0;

   for(int x = 1; x < 4 && (!p_op1 || !p_op2); x++)
      for(int y = 0; y < 3 && (!p_op1 || !p_op2); y++){
         if(operators[x][y] == op1)
            p_op1 = x;
         if(operators[x][y] == op2)
            p_op2 = x;
      }

   if(p_op1 > p_op2)
      return -1;
   else if(p_op1 == p_op2)
      return 0;
   else if(p_op1 < p_op2)
      return 1;
}

void printStack(const Stack* const s){
   if(s == NULL || s->top == NULL) return;

   Node* aux = s->top;
   for(; aux != NULL; aux = aux->next)
      printf("%c ", aux->character);
   putchar('\n');   
}

int isOperator(const char character){
   char *operators = {"()*^/-+%"};
   while(*operators){
      if(character == *operators++)
         return 1;
   }
   return 0;
}


#endif