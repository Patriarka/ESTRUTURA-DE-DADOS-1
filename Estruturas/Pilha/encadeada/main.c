#include <stdio.h>
#include <stdbool.h>

#include "tad_teste.h"
#include "pilha.h"

int main()
{
  char str[100];
  TipoElemento vetor[] = {4,3};
  TipoElemento saida;

  Teste* t = teste_criar("Teste pilha");
  Pilha *p = pilha_criar();

  teste_verificar(t, pilha_empilhar(p, 5) == true, "teste pilha_empilhar 1/4"); 
  teste_verificar(t, pilha_empilhar(p, 10) == true, "teste pilha_empilhar 2/4");
  teste_verificar(t, pilha_empilhar(p, 15) == true, "teste pilha_empilhar 3/4");
  teste_verificar(t, pilha_empilhar(NULL, 15) == false, "teste pilha_empilhar 13123123/4");
  pilha_imprimir(p); // [15,10,5]

  teste_verificar(t, pilha_toString(p, str) == true, "teste pilha_toString 1/2");
  teste_verificar(t, strcmp(str,"[15,10,5]") == 0, "teste pilha_toString 2/2");

  teste_verificar(t, pilha_desempilhar(p,&saida) == true, "teste pilha_desempilhar 1/5"); // [10,5]
  teste_verificar(t, saida == 15, "teste pilha_desempilhar 2/5"); 
  teste_verificar(t, pilha_desempilhar(p,&saida) == true, "teste pilha_desempilhar 3/5"); // [5]
  teste_verificar(t, saida == 10, "teste pilha_desempilhar 4/5"); 
  pilha_imprimir(p); // [5]

  teste_verificar(t, pilha_topo(p, &saida) == true, "teste pilha_topo 1/2"); // [5]
  teste_verificar(t, saida == 5, "teste pilha_topo 2/2"); 

  teste_verificar(t, pilha_tamanho(p) == 1, "teste pilha_tamanho 1/1"); // [5]
  teste_verificar(t, pilha_vazia(p) == false, "teste pilha_vazia 1/2"); // [5]
  teste_verificar(t, pilha_empilhar(p, 10) == true, "teste pilha_empilhar 4/4"); // [10,5]
  pilha_imprimir(p); // [10,5]

  Pilha* clone = pilha_clone(p);
  pilha_toString(clone, str);
  teste_verificar(t, strcmp(str,"[10,5]") == 0, "teste pilha_clone 1/1");
  pilha_imprimir(clone); // [10,5]

  pilha_inverter(p);
  pilha_toString(p, str);
  pilha_imprimir(p); // [5,10]
  teste_verificar(t, strcmp(str,"[5,10]") == 0, "teste pilha_inverter 1/1");

  teste_verificar(t, pilha_empilharTodos(p,vetor,2), "teste pilha_empilharTodos 1/1");

  pilha_imprimir(p); // [3,4,5,10]

  pilha_desempilhar(p,&saida);
  pilha_imprimir(p); // [4,5,10]

  pilha_desempilhar(p,&saida);
  pilha_imprimir(p); // [5,10]

  pilha_desempilhar(p,&saida);
  pilha_imprimir(p); // [10]

  pilha_desempilhar(p,&saida);

  teste_verificar(t, pilha_desempilhar(p,&saida) == false, "teste pilha_desempilhar 1/1");

  teste_verificar(t, pilha_vazia(p) == true, "teste pilha_vazia 2/2"); // [5] 

  pilha_destruir(&p);
  pilha_destruir(&clone);
  teste_relatorio(t);
  teste_desalocar(&t);  

  return 0;
}