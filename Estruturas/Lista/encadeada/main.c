#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tad_teste.h"
#include "tad_lista_dupla.h"

int main(){

  Teste* t = teste_criar("Teste Lista Duplamente Encadeada");
  Lista* l = lista_criar();

  teste_verificar(t, lista_inserir(l,5,0), "Teste lista_inserir (Início) 1/4"); 
  teste_verificar(t, lista_inserir(l,20,1), "Teste lista_inserir (Fim) 2/4");
  teste_verificar(t, lista_inserir(l,10,1), "Teste lista_inserir (Meio) 3/4");
  teste_verificar(t, lista_inserir(l,15,2), "Teste lista_inserir (Meio) 3/4");

  teste_verificar(t, lista_posicao(l, 5) == 0, "Teste lista_posicao 1/4");
  teste_verificar(t, lista_posicao(l, 10) == 1, "Teste lista_posicao 2/4");
  teste_verificar(t, lista_posicao(l, 15) == 2, "Teste lista_posicao 3/4");
  teste_verificar(t, lista_posicao(l, 20) == 3, "Teste lista_posicao 4/4");

  TipoElemento elemento;
  teste_verificar(t, lista_buscar(l,1,&elemento), "Teste lista_buscar 1/3");
  teste_verificar(t, elemento == 10, "Teste lista_buscar 2/3");
  teste_verificar(t, lista_buscar(l,20,&elemento) == false, "Teste lista_buscar 3/3");

  teste_verificar(t, lista_contem(l,5), "Teste lista_contem 1/4");
  teste_verificar(t, lista_contem(l,10), "Teste lista_contem 2/4");
  teste_verificar(t, lista_contem(l,20), "Teste lista_contem 3/4");
  teste_verificar(t, !lista_contem(l,70), "Teste lista_contem 4/4");

  teste_verificar(t, !lista_vazia(l), "Teste lista_vazia 1/2");
  teste_verificar(t, lista_tamanho(l) == 4, "Teste lista_tamanho 1/2");

  char str[200];
  lista_toString(l,str);
  teste_verificar(t, strcmp(str, "[5,10,15,20]") == 0, "Teste Lista_toString 1/3");
  lista_imprimir(l);

  teste_verificar(t, lista_substituir(l,0,1), "Teste lista_substituir 1/4");
  teste_verificar(t, lista_substituir(l,1,2), "Teste lista_substituir 2/4");
  teste_verificar(t, lista_substituir(l,2,3), "Teste lista_substituir 3/4");
  teste_verificar(t, lista_substituir(l,3,4), "Teste lista_substituir 4/4");

  lista_toString(l,str);
  teste_verificar(t, strcmp(str, "[1,2,3,4]") == 0, "Teste Lista_toString 1/3");
  lista_imprimir(l);

  TipoElemento removido;
  teste_verificar(t, lista_removerPosicao(l,1,&removido), "Teste lista_remover (Meio) 1/4");
  teste_verificar(t, lista_removerPosicao(l,2,&removido), "Teste lista_remover (Fim) 2/4");
  teste_verificar(t, lista_removerPosicao(l,0,&removido), "Teste lista_remover (Início) 3/4");
  teste_verificar(t, lista_removerPosicao(l,0,&removido), "Teste lista_remover (Elemento único) 4/4");
  lista_imprimir(l);

  lista_toString(l,str);
  teste_verificar(t, strcmp(str, "[]") == 0, "Teste Lista_toString 2/3");
  teste_verificar(t, lista_tamanho(l) == 0, "Teste lista_tamanho 2/2");

  teste_verificar(t, lista_vazia(l), "Teste lista_vazia 2/2");

  teste_verificar(t, lista_anexar(l,23), "Teste lista_anexar 1/2");
  teste_verificar(t, lista_anexar(l,30), "Teste lista_anexar 2/2");
  lista_imprimir(l);

  teste_verificar(t, lista_removerElemento(l,30) == 1, "Teste lista_removerElemento 1/2");
  teste_verificar(t, lista_removerElemento(l,23) == 0, "Teste lista_removerElemento 2/2");
  
  teste_relatorio(t);

  lista_destruir(&l);
  teste_desalocar(&t);  

  return 0;
}