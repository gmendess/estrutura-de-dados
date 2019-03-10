#ifndef _PROTO_H
#define _PROTO_H

typedef struct node{
   int value;
   struct node* next;
}Node;

typedef Node* Stack;

Stack* createStack();
void push(Stack* s, const int value);
int pop(Stack* s);
Node* createNode();
int calculate(const int num1, const int num2, const char op);
int exponentiation(int num1, const int num2);
void printStack(const Stack* const s);

#endif