#ifndef _SIMPLETRON_UTILS_H
#define _SIMPLETRON_UTILS_H

/* 
** Aqui é onde estão alguns typedefs e macros importantes 
*/

#define fast_int register int

#define SIMPLETRON_MEMORY 1000 // memória máxima do simpletron
#define MAX_FGETS_INPUT 10 // quantidade máxima de bytes lidos por FGETS

#define operand_module 100 // número usado no resto de divisão para achar o operando de uma instrucao. Ex.: 1234 % operand_module = 34
#define operation_module 100 // número usado no resto de divisão para achar o operador de uma instrucao

// macros de erro
#define NULL_POINTER_ERROR 10


#endif // _SIMPLETRON_UTILS_H