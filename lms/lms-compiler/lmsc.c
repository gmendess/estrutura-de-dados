#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include "lmsc.h"

LMS* createLMS() {
  LMS* lms = (LMS*) malloc(sizeof(LMS));

  if(lms) {
    lms->variable_pos = SIMPLETRON_MEMORY - 1;
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

  // essa variável será usada para armazenar o operando em instruções como READ/WRITE, dessa forma
  // ela armazenará a posição de alguma var/const no array do simpletron.
  // Ex.: var_position = 78; quero imprimir a posição 78, logo 1100 + var_position = 1178
  size_t var_position = 0;

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

      // instrução input (10)
      if( isInput(token) ) {
        // Pega o nome da variável
        token = getNextToken();

        // É necessário verificar se a variável já está na tabela de símbolos, antes de adicionar. Caso
        // contrário, você pode acabar duplicando sua variável na tabela de símbolos.
        var_position = symbolExists(table, token[0]);
        if(!var_position) { // se não existir na tabela de símbolos, insere
          addSymbol(table, lms->variable_pos, token[0], 'V');
          // var_position deixa de ser 0 e passa a ser a posição dessa nova variável. variable_pos é decrementada,
          // deixando a posição anterior para a próxima variável que vier.
          var_position = lms->variable_pos--;
        }

        // Agora é a parte de montar a instrução no "assembly" do Simpletron. Como esse é o READ, logo montaremos com o
        // código 11 + operando. As instruções na linguagem de máquina do Simpletron são salvas em lms->instructions
        lms->instructions[lms->instruction_count] = 1000 + var_position; // Exemplo.: 1000 + 99 = 1099 (Ler e armazenar na posição 99)

        // como input é uma instrução (READ), o contador de instruções é incrementado
        lms->instruction_count++;
      }

      token = getNextToken(); // pega o próximo token/símbolo
    } while(1);

  }
}


// adiciona um símbolo na tabela de símbolos. Lembre-se, o objetivo principal dessa tabela é de armazenar
// as variáveis/constantes a serem manipuladas. Cada uma deles possui uma posição na memória do simpletron,
// que é especificada pelo membro locale. Isso é uma nota pra mim mesmo, pq essa porcaria é confusa pra caramba
void addSymbol(Table* table, int locale, int value, char type) {
  // inicializa uma posição de table->vector com um Symbol
  table->vector[table->size] = (Symbol) {
    .locale = locale,
    .value = value,
    .type = type
  }; 
  ++table->size;
}

// verifica se o símbolo de valor `value` existe na tabela. Se existir retorna seu
// locale na memória do Simpletron, se não, retorna 0.
int symbolExists(Table* table, int value) {
  for(size_t i = 0; i < table->size; i++)
    if(table->vector[i].type != 'L' && table->vector[i].value == value)
      return table->vector[i].locale; // se for uma var/const, retornará a posição, como 99, 98, 97 etc
  return 0; // símbolo não encontrado na tabela, retorna 0
}