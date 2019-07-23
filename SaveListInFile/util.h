#ifndef MY_UTIL_FUNCTIONS_H
#define MY_UTIL_FUNCTIONS_H

#include "linked_list.h"

/* 
  Funções pra manipulação do arquivo binário
*/

#define OPEN_FAIL 10
#define NULL_FILE 11

// abre (se não existe, é criado) um arquivo binário no mode ab+ e retorna ponteiro para FILE
FILE* openFile();

// exporta nós de uma lista encadeada para um arquivo binário
int exportList(FILE* file, const List* const list);


#endif