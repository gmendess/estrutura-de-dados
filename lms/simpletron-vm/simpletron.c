#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "simpletron.h"
#include "utils.h"

#define parseOperand(instruction) ((instruction) % operand_module)
#define parseOperation(instruction) ((instruction) / operation_module)

// Cria e aloca memória para um ponteiro para um objeto de simpletron.
// Inicializa seus membros com um valor padrão e retorna o ponteiro
Simpletron* createSimpletron() {
  Simpletron* simpletron = (Simpletron*) malloc(sizeof(Simpletron));
  if(simpletron) {
    simpletron->total_instructions = 0;
    simpletron->accumulator = 0;

    simpletron->curr_instrucion = 0;
    simpletron->curr_operand = 0;
    
    memset(simpletron->memory, 0, sizeof(simpletron->memory));
  }
  return simpletron;
}

// Lê as instruções e as armazena na memória do simpletron
void loadInstructions(Simpletron* simpletron) {
  char buffer[MAX_FGETS_INPUT];
  size_t instruction = 0;

  if(!simpletron){
    fprintf(stderr, "Erro! Ponteiro nulo passado à loadInstructions.\n");
    exit(NULL_POINTER_ERROR);
  }

  for(int i = 0; i < SIMPLETRON_MEMORY / 2; i++) {
    printf("%0*d? ", (int)sizeof(i), i);
    if(!fgets(buffer, MAX_FGETS_INPUT - 1, stdin))
      break; // encerra o loop caso a entrada seja um EOF

    instruction = strtol(buffer, NULL, 10);
    simpletron->memory[i] = instruction;
    ++(simpletron->total_instructions);
  }
}

int run(Simpletron* simpletron) {
  if(!simpletron){
    fprintf(stderr, "Erro! Ponteiro nulo passado à run.\n");
    exit(NULL_POINTER_ERROR);
  }

  puts("=-=-=-=-=-=-=-=-=");

  size_t operand = 0;
  size_t operation = 0;
  size_t total_instructions = simpletron->total_instructions;
  size_t instruction = 0;

  /* Essa variável só existe pra fins de legibilidade. Uso ela ao invés de ter que 
   * ficar escrevendo `simpletron->curr_instrucion`. É um ponteiro, pois curr_instruction
   * pode sofrer alterações na operações de controle de fluxo, como o branch */
  size_t* index = &(simpletron->curr_instrucion);

  for(; *index < total_instructions; (*index)++){
    instruction = simpletron->memory[*index];
    operand = parseOperand(instruction);
    operation = parseOperation(instruction);

    // Switch-case para identificar a operação que deve ser realizada (ver simpletron.h para mais detalhes sobre as operações)
    switch (operation) {
      case READ:
        read(simpletron, operand);       break;
      case WRITE:
        write(simpletron, operand);      break;
      case LOAD:
        load(simpletron, operand);       break;
      case STORE:
        store(simpletron, operand);      break;
      case ADD:
        add(simpletron, operand);        break;
      case SUB:
        sub(simpletron, operand);        break;
      case DIV:
        _div(simpletron, operand);       break;
      case MUL:
        _mul(simpletron, operand);       break;
      case BRANCH:
        branch(simpletron, operand);     break;
      case BRANCHNEG:
        branchNeg(simpletron, operand);  break;
      case BRANCHZERO:
        branchZero(simpletron, operand); break;
      case HALT:
        halt(operand);                   break;
      default:
        fprintf(stderr, "Operação %ld inválida na posição %ld da memória!\n", operation, *index);
        break;
    } // fim do switch

  } // fim do for-loop

  return EXIT_FAILURE; // NUNCA DEVE CHEGAR AQUI. RUN DEVE RETORNAR ATRAVÉS DE UM HALT
}

/***********************************************************************/

void read(Simpletron* simpletron, const int operand) {
  printf("? ");
  scanf("%ld", &simpletron->memory[operand]);
}

void write(Simpletron* simpletron, const int operand) {
  printf("> %ld\n", simpletron->memory[operand]);
}

void load(Simpletron* simpletron, const int operand) {
  simpletron->accumulator = simpletron->memory[operand];
}

void store(Simpletron* simpletron, const int operand) {
  simpletron->memory[operand] = simpletron->accumulator;
}

void add(Simpletron* simpletron, const int operand) {
  simpletron->accumulator += simpletron->memory[operand];
}

void sub(Simpletron* simpletron, const int operand) {
  simpletron->accumulator -= simpletron->memory[operand];
}

void _div(Simpletron* simpletron, const int operand) {
  size_t _operand = simpletron->memory[operand];
  if(_operand == 0) {
    fprintf(stderr, "Erro: divisão por zero! Falha ao dividir %ld por 0.\n", simpletron->accumulator);
    exit(ZERO_DIVISION_ERROR);
  }
  simpletron->accumulator /= _operand;
}

void _mul(Simpletron* simpletron, const int operand) {
  simpletron->accumulator *= simpletron->memory[operand];
}

void branch(Simpletron* simpletron, const int operand) {
  // Digamos que operando seja igual a 3, isso significa que eu quero transferir o fluxo do meu programa
  // para a posição 3 do simpletron. Contudo, no for-loop, *index será incrementado, logo a posição passará
  // a ser 4. Dessa forma, para a posição ser correta, é necessário decrementar operand em 1, assim (3 - 1) = 2,
  // que quando incrementado fica 3.
  simpletron->curr_instrucion = operand - 1;
}

void branchNeg(Simpletron* simpletron, const int operand) {
  if(simpletron->accumulator < 0)
    simpletron->curr_instrucion = operand - 1;
}

void branchZero(Simpletron* simpletron, const int operand) {
  if(simpletron->accumulator == 0)
    simpletron->curr_instrucion = operand - 1;
}