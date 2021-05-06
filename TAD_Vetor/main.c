//main.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tad_teste.h"
#include "tad_vetor.h"

int main(){

  Teste* t1 = teste_criar("testes para verificar funções do vetor");

  Vetor* vet = NULL;
  
  vet = vet_criar(3);
  teste_verificar(t1, vet != NULL, "verificar criação do vetor");

  teste_verificar(t1, vet_tamanho_alocado(vet) == 3, "verificar tamanho alocado");
  teste_verificar(t1, vet_criar(-1) == NULL, "verificar criação do vetor (erro: -1 nulo)");

  teste_verificar(t1, vet_anexar(vet,30), "verificar inserção no fim"); // [30]
  teste_verificar(t1, vet_anexar(vet,40), "verificar inserção no fim"); // [30,40]

  teste_verificar(t1, vet_tamanho_alocado(vet) == 3, "verificar tamanho alocado");

  teste_verificar(t1, vet_inserir(vet,10,0), "verificar inserção no início"); // [10,30,40] 
  teste_verificar(t1, vet_inserir(vet,20,1), "verificar inserção no meio"); // [10,20,30,40] 
  teste_verificar(t1, vet_inserir(vet,50,5), "verificar inserção no fim"); // [10,20,30,40,50] 

  char str[100];
  teste_verificar(t1, vet_toString(vet,str), "verificar vetor para string"); 
  teste_verificar(t1, strcmp(str,"[10,20,30,40,50]") == 0, "verificar vetor"); 
  teste_verificar(t1, vet_tamanho(vet) == 5, "verificar vetor"); 

  int elemento;
  teste_verificar(t1, vet_elemento(vet, 0, &elemento), "verificar elemento no vetor"); 
  teste_verificar(t1, vet_elemento(vet, -1, &elemento) == false, "verificar elemento no vetor (erro: posição inválida)"); 
  teste_verificar(t1, elemento = 10, "verificar elemento no vetor"); 

  teste_verificar(t1, vet_substituir(vet, 0, 8), "substituir elemento no vetor"); // [8,20,30,40,50] 
  teste_verificar(t1, vet_substituir(vet, -1, 8) == false, "substituir elemento no vetor (erro: posição inválida)");

  teste_verificar(t1, vet_removerPosicao(vet, 0, &elemento), "remover elemento no início"); // [20,30,40,50] 
  teste_verificar(t1, elemento == 8, "comparar elemento removido"); 
  teste_verificar(t1, vet_removerPosicao(vet, 1, &elemento), "remover elemento no meio"); // [20,40,50] 
  teste_verificar(t1, elemento == 30, "comparar elemento removido"); 
  teste_verificar(t1, vet_removerPosicao(vet, 2, &elemento), "remover elemento no fim"); // [20,40] 
  teste_verificar(t1, elemento == 50, "comparar elemento removido"); 

  teste_verificar(t1, vet_removerElemento(vet, 40), "verificar remoção do elemento"); // [20]
  teste_verificar(t1, vet_toString(vet,str), "verificar vetor para string"); 
  teste_verificar(t1, vet_tamanho_alocado(vet) == 3, "verificar tamanho alocado");

  teste_verificar(t1, strcmp(str,"[20]") == 0, "verificar vetor"); 

  teste_verificar(t1, vet_posicao(vet, 20) == 0, "verificar posição do elemento no vetor"); 
  
  vet_inserir(vet,1,0); // [1,20]
  vet_inserir(vet,2,0); // [2,1,20]
  vet_inserir(vet,3,0); // [3,2,1,20]

  teste_verificar(t1, vet_toString(vet,str), "verificar vetor para string");
  teste_verificar(t1, strcmp(str,"[3,2,1,20]") == 0, "verificar vetor"); 

  vet_desalocar(vet);
  vet = NULL;

  teste_relatorio(t1);
  teste_desalocar(&t1);

  return 0;
}


