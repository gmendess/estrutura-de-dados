#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "func.c"

int main(){

   Tree* tr = create_tree();

   new_node(&tr->root, 10);
   new_node(&tr->root, 5);
   new_node(&tr->root, 3);
   new_node(&tr->root, 20);
   new_node(&tr->root, 19);
   new_node(&tr->root, 30);

   preOrder(tr->root);
   puts("");
   
   free_tree(tr);
   
   preOrder(tr->root);
   puts("");
   return 0;
}