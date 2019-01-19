#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

typedef struct node{
   int value;
   struct node* left;
   struct node* right;
}Node;

typedef struct tree{
   Node* root;
}Tree;


Tree* create_tree();
int new_node(Node** subtree, const int value);
int search(Node** subtree, const int key_value);
int remove_from_tree(Tree* subtree, const int key_value);
Node* remove_current(Node* current);
void preOrder(Node* node);
void inOrder(Node* node);
void postOrder(Node* node);

#endif