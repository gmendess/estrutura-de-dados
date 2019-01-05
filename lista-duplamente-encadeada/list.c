#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#include "prototypes.h"

int main(){

   List* li = create_list();

   if(add_at_end(li, 10))
      puts("Valor inserido com sucesso!");
   if(add_at_end(li, 11))
      puts("Valor inserido com sucesso!");
   if(add_at_end(li, 12))
      puts("Valor inserido com sucesso!");
   if(add_at_end(li, 13))
      puts("Valor inserido com sucesso!");
   if(remove_by_index(li, 1))
      puts("Valor removido com sucesso!");


   putchar('\n');
   print_list(li);
      

   return EXIT_SUCCESS;
}