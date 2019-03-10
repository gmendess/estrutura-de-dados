#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "func.c"

int main(){

   char postfix[50] = {"22^2^"}; // 2^2^2
   postfix[strlen(postfix)] = '\0';

   Stack* s = createStack();

   int  num1   = 0, 
        num2   = 0,
        result = 0;
   char op     = 0;

   for(int x = 0; postfix[x] != '\0'; x++){
      if(isdigit(postfix[x]) != 0)
         push(s, postfix[x] - 48);
      else{
         num1 = pop(s);
         num2 = pop(s);
         op = postfix[x];
         result = calculate(num1, num2, op);
         push(s, result);
      }
   }
   result = pop(s);
   printf("O resultado da operação é %d\n", result);
   


   return EXIT_SUCCESS;
}
