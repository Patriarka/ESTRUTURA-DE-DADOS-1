/* //main.c

#include <stdio.h>
#include <stdlib.h>

#include "tad_teste.h"
#include "tad_vetor.h"

int main(){

  Teste* t1 = teste_criar("testes para verificar funções do vetor");

  Vetor* vet = NULL;
  Vetor* vet2 = NULL;
  
  vet = vet_criar(3);
  teste_verificar(t1, vet != NULL, "verificar criação do vetor");

  teste_verificar(t1, vet_tamanho_alocado(vet) == 3, "verificar tamanho alocado");

  vet2 = vet_criar(-1);
  teste_verificar(t1, vet2 != NULL, "verificar criação do vetor (erro: vet2 nulo)");

  teste_verificar(t1, vet_anexar(vet,30), "verificar inserção no fim"); // [30]
  teste_verificar(t1, vet_anexar(vet,40), "verificar inserção no fim"); // [30,40]
  teste_verificar(t1, vet_anexar(vet2,50), "verificar inserção em um Vetor nulo (erro: vet2 nulo)"); 

  teste_verificar(t1, vet_tamanho_alocado(vet) == 3, "verificar tamanho alocado");

  teste_verificar(t1, vet_inserir(vet,10,0), "verificar inserção no início"); // [10,30,40] 
  teste_verificar(t1, vet_inserir(vet,20,1), "verificar inserção no meio"); // [10,20,30,40] 
  teste_verificar(t1, vet_inserir(vet,50,5), "verificar inserção no fim"); // [10,20,30,40,50] 
  teste_verificar(t1, vet_inserir(vet2,20,1), "verificar inserção em um Vetor nulo (erro: vet2 nulo)"); 

  char str[100];
  teste_verificar(t1, vet_toString(vet,str), "verificar vetor para string"); 

  teste_verificar(t1, strcmp(str,"[10,20,30,40,50]") == 0, "verificar vetor"); 
  teste_verificar(t1, strcmp(str,"[10,20,30,40,60]") == 0, "verificar vetor (erro: vetor diferente)"); 

  teste_verificar(t1, vet_tamanho(vet) == 5, "verificar vetor"); 

  int elemento;
  teste_verificar(t1, vet_elemento(vet, 0, &elemento), "verificar elemento no vetor"); 
  teste_verificar(t1, vet_elemento(vet, -1, &elemento), "verificar elemento no vetor (erro: posição inválida)"); 
  teste_verificar(t1, elemento = 10, "verificar elemento no vetor"); 

  teste_verificar(t1, vet_substituir(vet, 0, 8), "substituir elemento no vetor"); // [8,20,30,40,50] 
  teste_verificar(t1, vet_substituir(vet, -1, 8), "substituir elemento no vetor (erro: posição inválida)");

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

  teste_relatorio(t1);
  teste_desalocar(&t1);

  return 0;
}
 */

//main.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tad_teste.h"
#include "tad_vetor.h"

Teste* teste_criar(char* descricao);
void teste_verificar(Teste* t, int condicao, char *mensagem);
void teste_relatorio(Teste* t);
void teste_desalocar(Teste** t);

int main(){

	// Desenvolva os testes para verificar se a função implementada 
  //está funcionando como esperado
	
	char str[100];

	Teste* t = teste_criar("Teste para TAD Vetor");

	Vetor* v1 = vet_criar(100);
	vet_anexar(v1, 10);   //[10]
	vet_anexar(v1, 20);   //[10,20]
	vet_anexar(v1, 30);   //[10,20,30]
	vet_toString(v1, str);// "[10,20,30]"
  teste_verificar(t, strcmp(str,"[10,20,30]") == 0, "Teste das funcoes criar e anexar");

  vet_inserir(v1,15,1);  //[10,15,20,30]
	vet_toString(v1, str);// "[10,15,20,30]"
  teste_verificar(t, strcmp(str,"[10,15,20,30]") == 0, "Teste 1 da funcao inserir (meio)");

  vet_inserir(v1,5,0);  //[5,10,15,20,30]
	vet_toString(v1, str);// "[5,10,15,20,30]"
  teste_verificar(t, strcmp(str,"[5,10,15,20,30]") == 0, "Teste 2 da funcao inserir (inicio)");

	int tam = vet_tamanho(v1);
  vet_inserir(v1,40,tam);  //[5,10,15,20,30,40]
	vet_toString(v1, str);// "[5,10,15,20,30,40]"
  teste_verificar(t, strcmp(str,"[5,10,15,20,30,40]") == 0, "Teste 3 da funcao inserir (fim)");

	bool x = vet_inserir(v1,100,10);
	vet_toString(v1, str);// "[5,10,15,20,30,40]"  
  teste_verificar(t, x == false, "Teste 4 da funcao inserir (posicao invalida)");
  teste_verificar(t, strcmp(str,"[5,10,15,20,30,40]") == 0, "Teste 4 da funcao inserir (posicao invalida)");

	x = vet_inserir(v1,100,-5);
	vet_toString(v1, str);// "[5,10,15,20,30,40]"  
  teste_verificar(t, x == false, "Teste 5 da funcao inserir (posicao invalida)");
  teste_verificar(t, strcmp(str,"[5,10,15,20,30,40]") == 0, "Teste 5 da funcao inserir (posicao invalida)");

	teste_relatorio(t);
	teste_desalocar(&t);

	v1 = vet_criar(100);
	vet_anexar(v1, 10);   //[10]
	vet_anexar(v1, 20);   //[10,20]
	vet_anexar(v1, 30);   //[10,20,30]

	vet_inserir(v1,15,1);  //[10,15,20,30]
	vet_inserir(v1,5,0);   //[5,10,15,20,30]
	vet_inserir(v1,40,5);   //[5,10,15,20,30,40]

	vet_substituir(v1,0,7);   //[7,10,15,20,30,40]
	
	int elemento = 0; 
	vet_removerPosicao(v1,0,&elemento);   //[10,15,20,30,40]
	printf("%d\n", elemento);             // 7
	
	int pos = vet_removerElemento(v1, 30);   //[10,15,20,40]
	printf("%d\n", pos);                     // 3

	pos = vet_removerElemento(v1, 250);   //[10,15,20,40]
	printf("%d\n", pos);                     // -1
	if(pos == -1) printf("O elemento não foi encontrado");

	//  int n = v1[1];
  int n;
	vet_elemento(v1,1, &n); 
	
	str[100];
	vet_toString(v1, str);
	printf("%s \n", str); // "[10,15,20,40]"
  
}