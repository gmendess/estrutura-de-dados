#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include "lmsc.h"

LMS* createLMS() {
  LMS* lms = (LMS*) malloc(sizeof(LMS));

  if(lms) {
    lms->variable_count = SIMPLETRON_MEMORY - 1;
    lms->instruction_count = 0;
    memset(lms->instructions, 0, sizeof(lms->instructions));

    // inicializa todas as posições de flags com -1
    for(size_t i = 0; i < SIMPLETRON_MEMORY; lms->flags[i++] = -1);
  }
  return lms;
}

Table* createTable() {
  Table* table = (Table*) malloc(sizeof(Table));

  if(table) {
    table->size = 0;
    memset(table->vector, 0, sizeof(table->vector));
  }

  return table;
}


void readInstructions(LMS* lms, Table* table, FILE* const file) {
  size_t line; // número da linha sendo lida
  char buffer[100]; // buffer para o resto das instrução
  char* token; // token para cada pedaço de buffer

  while(!feof(file)) {
    // lê a número da linha e a instrução restante
    fscanf(file, "%ld %[^\n]", &line, buffer);

    // Esse addSymbol adiciona a linha na tabela de símbolos. Ela pode eventualmente ser usada em um goto
    // Como ela não é uma instrução, instruction_count não é incrementado
    addSymbol(table, lms->instruction_count, line, 'L');

    // Agora começa o parser do buffer, que contém o resto da instrução

    token = strtok(buffer, " "); // pega a primeira parte da string usando um espaço como delimitador
    do {
      if(!token || strcmp(token, "rem") == 0) 
        break; // token é nulo ou rem (como rem é um comenario, o resto do conteúdo deve ser ignorado)

      puts(token);
      token = strtok(NULL, " "); // pega o próximo token usando espaço como delimitador
    } while(1);

  }
}

void addSymbol(Table* table, int locale, int value, char type) {
  // inicializa uma posição de table->vector com um Symbol
  table->vector[table->size] = (Symbol) {
    .locale = locale,
    .value = value,
    .type = type
  }; 

  ++table->size;
}