#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "func.c"

int main(){

   char infix[50] = {"(6+2)*5-8/4"}; //expressão aritmética no formato infix
   char postfix[50] = {0}; //expressão no formato postfix será salva nesse vetor 

   Stack* s = createStack();

   push(s, '(');
   infix[strlen(infix)] = ')';

   int pf_size = 0;
   for(int x = 0; x < strlen(infix); x++){
      if( isdigit(infix[x]) != 0 )
         postfix[pf_size++] = infix[x];
      
      else if(infix[x] == '(')
         push(s, infix[x]);

      else if(infix[x] == ')'){
         while(s->top->character != '(')
            postfix[pf_size++] = pop(s);
         pop(s);
      }
      
      else if(isOperator(s->top->character)){
         while(verifyPrecedence(s->top->character, infix[x]) <= 0)
            postfix[pf_size++] = pop(s);
         push(s, infix[x]);
      }
   }

   puts(postfix);

   return EXIT_SUCCESS;
}