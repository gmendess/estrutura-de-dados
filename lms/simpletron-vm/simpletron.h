#ifndef _SIMPLETRON_H_
#define _SIMPLETRON_H_

#include "utils.h"

typedef struct _simpletron {
  size_t memory[SIMPLETRON_MEMORY]; // memória do simpletron
  size_t accumulator; 
  size_t total_instructions;
  size_t curr_instrucion;
  size_t curr_operand;
} Simpletron;

// Enum com todas as operações que podem ser executadas pelo Simpletron
typedef enum _simpletron_operations {
  /*  Operações de entrada/saída */
  READ = 10, // Lê entrada do usuário
  WRITE, // mostra na tela um valor armazenado na memória do Simpletron

  /* Operações de manipulação da memória do Simpletron */
  LOAD = 20, // carrega no acumulador um valor armazenado na memória do Simpletron
  STORE, // armazena na memória do Simpletron o valor contido no acumulador 

  /* Operações aritméticas */
  ADD = 30, // soma ao acumulador um valor contido na memória do Simpletron 
  SUB, // subtrai do acumulador um valor contido na memória do Simpletron
  DIV, // divide o acumulador por um valor contido na memória do Simpletron
  MUL, // multiplica o acumulador por um valor contido na memória do Simpletron

  /* Operações de controle de fluxo */
  BRANCH = 40, // transfere o fluxo de execução para um local da memória do Simpletron
  BRANCHNEG, //  caso o acumulador seja negativo, transfere o fluxo de execução para um local da memória do Simpletron
  BRANCHZERO, //  caso o acumulador seja zero, transfere o fluxo de execução para um local da memória do Simpletron
  HALT // encerra a execução do programa
} SimpletronOperations;

Simpletron* createSimpletron();
void loadInstructions(Simpletron* simpletron);
void run(Simpletron* simpletron);

// Protótipos das operações que o Simpletron pode realizar
void read(Simpletron* simpletron, const int operand); 






#endif // _SIMPLETRON_H_