#ifndef MY_UTIL_FUNCTIONS_H
#define MY_UTIL_FUNCTIONS_H

#include "linked_list.h"

/* 
  Funções pra manipulação do arquivo binário
*/

#define OPEN_FAIL    10
#define NULL_FILE    11
#define INVALID_FILE 12

// abre (se não existe, é criado) um arquivo binário no mode rb e retorna ponteiro para FILE
FILE* openFile();

// exporta nós de uma lista encadeada para um arquivo binário
// Nota: ele reabre o arquivo em modo wb para apagar o conteúdo antes de exportar os nós
int exportList(FILE* file, const List* const list);

// importa nós de uma lista encadeada para um arquivo binário
int importList(FILE* file, List* const list);


#endif