#ifndef _FUNC_H
#define _FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

Tree* create_tree(){
   Tree* tr = (Tree*) malloc(sizeof(Tree));
   if(tr != NULL)
      tr->root = NULL;
   return tr;
}

int new_node(Node** subtree, const int value){
   if(*subtree == NULL){
      Node* new_node = (Node*) malloc(sizeof(Node));
      new_node->left = NULL;
      new_node->right = NULL;
      new_node->value = value;
      *subtree = new_node;
      return 1;
   }

   if(value > (*subtree)->value)
      return new_node(&(*subtree)->right, value);
   else if(value < (*subtree)->value)
      return new_node(&(*subtree)->left, value);

   return 0;
}

int remove_from_tree(Tree* tr, const int key_value){
   if(tr == NULL || tr->root == NULL)
      return 0;

   Node* prev = NULL, 
       * current = tr->root;
        
   while(current != NULL){
      if(current->value == key_value){
         if(current == tr->root){
            tr->root = remove_current(current);
         }else{
            if(current == prev->right){
               prev->right = remove_current(current);
            }else{
               prev->left = remove_current(current);
            }
         }
         return 1;
      }
      prev = current;
      if(key_value > current->value)
         current = current->right;
      else
         current = current->left;
   }
   return 0;
}

Node* remove_current(Node* current){
   Node* nodeA, *nodeB;
   if(current->left == NULL){
      nodeA = current->right;
      free(current);
      return nodeA;      
   }

   nodeA = current;
   nodeB = current->left;
   while(nodeB->right != NULL){
      nodeA = nodeB;
      nodeB = nodeB->right;
   }

   if(nodeA != current){
      nodeA->right = nodeB->left;
      nodeB->left = current->left;
   }
   nodeB->right = current->right;
   free(current);
   return nodeB;
}

int search(Node** subtree, const int key_value){
   if(*subtree == NULL)
      return 0;
   
   //printf("%d\n", (*subtree)->value);

   if((*subtree)->value == key_value)
      return 1;
   else if(key_value > (*subtree)->value)
      return search(&(*subtree)->right, key_value);
   else if(key_value < (*subtree)->value)
      return search(&(*subtree)->left, key_value);
}


void preOrder(Node* subtree) {
   if(subtree == NULL)
      return;
   printf("%d ", subtree->value);
   preOrder(subtree->left);
   preOrder(subtree->right);
}

void postOrder(Node* subtree){
   if(subtree == NULL)
      return;
   postOrder(subtree->left);
   postOrder(subtree->right);
   printf("%d ", subtree->value);
}

void inOrder(Node* subtree){
   if(subtree == NULL)
      return;
   inOrder(subtree->left);
   printf("%d ", subtree->value);
   inOrder(subtree->right);
}

void free_tree(Tree* tr){
   if(tr == NULL) return;
   free_node(tr->root);
   free(tr);
   tr->root = NULL;
   tr = NULL;
}

void free_node(Node* node){
   if(node == NULL) return;
   free_node(node->left);
   free_node(node->right);
   free(node);
   node = NULL;
}


#endif 