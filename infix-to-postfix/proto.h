#ifndef _PROTO_H
#define _PROTO_H

typedef struct node{
   char character;
   struct node* next;
}Node;

typedef struct stack{
   int size;
   Node* top;
}Stack;

Stack* createStack();
Node* createNode();
int push(Stack* s, const char data);
char pop(Stack* s);
int isEmpty(Stack* s);
int verifyPrecedence(const char op1, const char op2);
void printStack(const Stack* const s);
int isOperator(const char character);

#endif