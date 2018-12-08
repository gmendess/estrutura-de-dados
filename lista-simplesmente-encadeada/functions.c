#ifndef _LIST_FUNCTIONS_H
#define _LIST_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include "prototypes.h"

//Função que aloca espaço para a lista e inicializa seus valores
List* create_list(){
   List* list = (List*) malloc(sizeof(List));
   list->head = NULL;
   list->size = 0;
   return list;
}

//Função que adiciona um nó no final da lista
void append(List* list, DataNode data){
   if(!list)
      return;
   
   //cria o novo nó e atribui seus valores
   Node* new_node = (Node*) malloc(sizeof(Node));
   new_node->data = data;
   new_node->next = NULL; //como ele vai ser o último nó, seu seu next tem que apontar para NULL;

   if(list->head == NULL) //verificando se a lista está vazia, ou seja, se list->head aponta para NULL
      list->head = new_node; //se estiver, list->head passa a apontar para o novo nó
   else{ 
      Node* aux = list->head; 
      while(aux->next != NULL){ // se não, percorre toda a lista com um nó auxiliar até chegar no último nó 
         aux = aux->next;
      }
      aux->next = new_node; /*o nó auxiliar se torna o último nó da lista, pois ele a percorreu por completo, assim
                              seu next passa a ser o novo nó
                            */
   }
   list->size++; //incrementa o tamanho da lista
}

void printList(List* list){
   if(!list)
      return;
   else if(list->head == NULL){
      puts("Lista vazia!");
      return;
   }else{
      Node* aux = list->head;
      puts("+-----------------+----+");
      puts("| NOME            | ID |");
      puts("+-----------------+----+");
      while(aux != NULL){
         printf("| %-15s | %-2d |\n", 
                 aux->data.nome, aux->data.id);
         aux = aux->next;
      }
      puts("+-----------------+----+\n");
   }
}

//Insere um novo nó em qualquer posição da lista
void insert(List* list, DataNode data, const int index){
   if(!list)
      return;
   if(index < 0)
      return;
   if(index > list->size)
      return;
   
   //cria o novo nó
   Node* new_node = (Node*) malloc(sizeof(Node));
   new_node->data = data;
   
   //se index for == 0, significa que desejo inserir no inicio da lista
   if(index == 0){
      new_node->next = list->head; //assim, new_node->next tem que apontar para quem list->head apontava
      list->head = new_node; //e list->head tem que apontar para o new_node
   }else{ //se index for != 0
      Node* prevNode = atPos(list, index-1); //pego o nó anterior da posição que eu desejo adicionar meu novo nó
      Node* aux = prevNode->next; //salvo no nó auxiliar o nó que prevNode->next apontava

      prevNode->next = new_node; //faço prevNode apontar para new_node
      new_node->next = aux; //e new_node->next apontar para quem prevNode->next apontava (salvo em aux)
   }
   list->size++;
}

//Retorna o nó contido em determinada posição
Node* atPos(List* list, const int index){
   if(!list || list->head == NULL)
      return NULL;
   if(index < 0 || index > (list->size-1))
      return NULL;
   
   //Cria nó auxiliar
   Node* aux = list->head;
   //percorre toda a lista com o nó auxiliar enquanto não chegar no index que quero e enquanto o nó auxiliar for diferente de NULL
   for(int x = 0; x != index && aux != NULL; x++, aux = aux->next);
   return aux; //retorna o nó auxiliar
}

//Retorna a posição de determindo nó
int indexOf(List* list, const Node* const node){
   if(!list || !node)
      return -1;
   
   //cria nó auxiliar
   Node* aux = list->head;
   //percorre toda a lista enquanto aux for diferente de NULL
   for(int x = 0; aux != NULL; x++, aux = aux->next)
      if(aux == node) //se aux for igual ao nó passado
         return x; //retorna 'x', contendo a posição do nó
   return -1;
}

//Remove um nó da lista com base na posição passada
void pop(List* list, const int index){
   if(!list)
      return;
   if(list->head == NULL)
      return;
   if(index > list->size-1)
      return;

   //Cria nó auxiliar, usando o atPos para pegar o nó contido na posição que desejo excluir
   Node* aux = atPos(list, index);
   if(index == 0){ //se index == 0, significa que eu quero remover o primeiro nó, ou seja, quem list->head aponta
      list->head = list->head->next; //list->head passa a apontar para list->head->next(no caso, seria o segundo nó da lista)
      free(aux); //libera a memória apontada por aux
   }else{ // se index > 0
      Node* prev = atPos(list, index-1); //pego o nó anterior ao nó que quero excluir
      prev->next = aux->next; //faço prev->next apontar para quem aux->next aponta
      free(aux); //libera a memória apontada por aux
   }
   list->size--; //decremento o tamanho da lista
}

//Função que excluir todos os nós da lista
void clear(List *list){
   while(list->size != 0) //enquanto o tamanho da lista for diferente de 0
      pop(list, 0); //chama a função pop para excluir os primeiros nó da lista
}

//Excluir a lista
void delList(List *list){
   clear(list); //exclui todos os nós da lista
   free(list->head); //libera a memória apontada por list->head
   free(list); //libera a memória apontada por list 
}

//Função que troca dois nós de lugar
void swapNodes(List* list, Node* nodeA, Node* nodeB){
   /*
      Trocar um nó de lugar com o outro é fazer com que cada um seja apontado pelo nó anterior
      do outro, e cada um apontar para quem o outro aponta. Exemplo: eu passo a ser apontado por quem
      te aponta, e você passa a ser apontado por quem me aponta. Eu passo a apontar para quem você aponta
      e você passa a apontar para quem eu apontava.
   */

   if(!list)
      return;
   if(nodeA == nodeB) //verifica se os dois nós são iguais
      return;
   if(!nodeA || !nodeB) //verifica se um dos nós é NULL
      return;

   int indexA = indexOf(list, nodeA); //pega o index de nodeA
   int indexB = indexOf(list, nodeB); //pega o index de nodeB

   //verifica se o indexA > indexB, ou seja, se o nodeA vem após o nodeB
   if(indexA > indexB){ //se for verdadeiro
      nodeA = nodeB; //nodeA aponta para quem nodeB aponta
      nodeB = atPos(list, indexA); //nodeB aponta para quem nodeA apontava

      indexA = indexB; //indexA passa a ser o indexB
      indexB = indexOf(list, nodeB); //indexB passa a apontar para indexA
      /*
         As instruções contidas nesse bloco faz com que o único nó passível de ser o list->head seja o nodeA,
         isso pois nodeA sempre será anterior ao nodeB, evitando que nodeB possa ser list->head. Isso facilita
         verificar se um dos nós é list->head, pois como apenas o nodeA pode ser, então só é necessário fazer
         a verificação nele.
      */
   
   }

   //pega o nó anterior ao nodeB
   Node* prevB = atPos(list, indexB-1);
   if(nodeA == list->head){ //se nodeA == list->head 
      list->head = nodeB; //list->head passa a apontar para o nodeB 
   }else{ //se não
      Node* prevA = atPos(list, indexA-1); //pega o nó anterior ao nodeA
      prevA->next = nodeB; //e faz prevA->next apontar para o nodeB
   }

   prevB->next = nodeA;//prevB->next passa a apontar para o nodeA
   Node* aux = nodeB->next; //salva no nó aux o nodeB-next
   nodeB->next = nodeA->next; //nodeB->next aponta para quem nodeA->next aponta
   nodeA->next = aux;//nodeA->next aponta para quem nodeB->next apontava (salvo em aux)
}

//Pega o menor ID da lista iniciando a partir da posição passada
Node* min(List* list, const int index){
   Node* aux = atPos(list, index); //armazena no nó auxiliar o nó da posição passada. Será usado para percorrer a lista
   Node* minID = aux; //minID aponta para aux
   for(int x = index; x < list->size; x++){ //enquanto x < list->head (observe que x recebe o valor de index)
      if(minID->data.id > aux->data.id) //verifica se o id de minID é maior que o id de aux
         minID = aux; //se for, o minID passa a ser aux
      aux = aux->next; //aux aponta para aux->next, ou seja, pro próximo nó da lista
   }
   return minID; //retorna minID
}

//Pega o maior ID da lista iniciando a partir da posição passada
Node* max(List* list, const int index){
   Node* aux = atPos(list, index); //armazena no nó auxiliar o nó da posição passada. Será usado para percorrer a lista
   Node* maxID = aux; //maxID aponta para aux
   for(int x = index; x < list->size; x++){ //enquanto x < list->head (observe que x recebe o valor de index)
      if(maxID->data.id < aux->data.id) //verifica se o id de maxID é menor que o id de aux
         maxID = aux; //se for, o maxID passa a ser aux
      aux = aux->next; //aux aponta para aux->next, ou seja, pro próximo nó da lista
   }
   return maxID; //retorna maxID
}

//Ordena a lista em ordem ascendente/crescente
void ascSort(List* list){
   //percorre a lista enquanto x for menor do que list->size-2
   for(int x = 0; x < list->size-2; x++) //list->size-2: -1 pois a lista inicia da posição 0, e -1 pq 
                                         //a último verificação não é necessária, já que os nós serão iguais, totalizando -2
      swapNodes(list, atPos(list, x), min(list, x)); //troca o nó da posição x pelo "menor nó" a partir da posição x

}

//Ordena a lista em ordem descendente/decrescente
void descSort(List* list){
   //percorre a lista enquanto x for menor do que list->size-2
   for(int x = 0; x < list->size-2; x++)//list->size-2: -1 pois a lista inicia da posição 0, e -1 pq 
                                        //a último verificação não é necessária, já que os nós serão iguais, totalizando -2
      swapNodes(list, atPos(list, x), max(list, x)); //troca o nó da posição x pelo "maior nó" a partir da posição x
}

#endif