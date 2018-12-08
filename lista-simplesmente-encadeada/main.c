#include <stdlib.h>
#include <stdio.h>
#include "functions.c"

int main(void){

   List* list = create_list();

   DataNode a = {"Amanda", 1};
   DataNode b = {"Bruno", 2};
   DataNode c = {"Carlos", 3};
   DataNode d = {"Daniele", 4};

   append(list, d);
   append(list, c);
   append(list, b);
   append(list, a);

   printList(list);
   
   ascSort(list);
   printList(list);
   
   descSort(list);
   printList(list);

   return EXIT_SUCCESS;
}