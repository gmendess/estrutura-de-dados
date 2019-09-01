#ifndef _LMSC_H
#define _LMSC_H

#include "utils.h"

// Struct que representa casa símbolo na tabela de símbolos
struct _symbol {
  int locale; // local na memória do Simpletron
  int value; // valor que representa o símbolo
  char type; // tipo do símbolo. "L"inha, "V"ariável ou "C"onstante
};
typedef struct _symbol Symbol;

// Struct que representa a table de símbolos
struct _symbol_table {
  Symbol vector[SIMPLETRON_MEMORY]; // vetor de Symbol de tamanho SIMPLETRON_MEMORY
  int size; // quantidade de símbolos na tabela de símbolos
};
typedef struct _symbol_table Table;

// Núcleo do compilador. Contém tanto o vetor de flags, quanto as instruções a serem executadas pelo Simpletron
struct _lms {
  size_t instruction_count; // contador para instruções (deve ser inicializado com 0)
  size_t variable_count; // contador para variáveis/constantes (deve ser inicializado com SIMPLETRON_MEMORY - 1)
  size_t instructions[SIMPLETRON_MEMORY]; // instruções a serem executadas em lms
  int flags[SIMPLETRON_MEMORY]; // marcações para referências antecipadas
};
typedef struct _lms LMS;

/*******************************************************************************************/

LMS* createLMS();
Table* createTable();

void readInstructions(LMS* lms, Table* table, FILE* const file);
void addSymbol(Table* table, int locale, int value, char type);

#endif // _LMSC_H