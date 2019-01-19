#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "func.c"

int main(){

   Node* teste = NULL,
       * a123 = NULL;

   srand(time(0));
   Tree* tr = create_tree();

   //for(int x = 0; x < 10; x++)
   //   new_node(&tr->root, rand() % 100);

   new_node(&tr->root, 10);
   new_node(&tr->root, 5);
   new_node(&tr->root, 3);
   new_node(&tr->root, 20);
   new_node(&tr->root, 19);
   new_node(&tr->root, 30);
   preOrder(tr->root);
   puts("");
   remove_from_tree(tr, 10);
   preOrder(tr->root);
   puts("");
   return 0;
}