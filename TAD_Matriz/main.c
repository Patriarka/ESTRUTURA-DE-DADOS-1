#include <stdio.h>
#include <stdlib.h>

#include "tad_teste.h"
#include "tad_matriz.h"

int main(){

  Teste* t1 = teste_criar("testes para verificar funções do vetor");
  
  Matriz* mat = NULL;
  mat = mat_criar(3,3);
  teste_verificar(t1, mat != NULL, "verificar criação da matriz");

  teste_verificar(t1, mat_atribuir(mat, 0, 0, 0.25), "verificar inserção na matriz");
  teste_verificar(t1, mat_atribuir(mat, 0, 1, 0.50), "verificar inserção na matriz");
  teste_verificar(t1, mat_atribuir(mat, 0, 2, 0.75), "verificar inserção na matriz");
  teste_verificar(t1, mat_atribuir(mat, 1, 0, 1.00), "verificar inserção na matriz");
  teste_verificar(t1, mat_atribuir(mat, 1, 1, 1.25), "verificar inserção na matriz");
  teste_verificar(t1, mat_atribuir(mat, 1, 2, 1.50), "verificar inserção na matriz");
  teste_verificar(t1, mat_atribuir(mat, 2, 0, 1.75), "verificar inserção na matriz");
  teste_verificar(t1, mat_atribuir(mat, 2, 1, 2.00), "verificar inserção na matriz");
  teste_verificar(t1, mat_atribuir(mat, 2, 2, 2.25), "verificar inserção na matriz");

  float elemento;
  teste_verificar(t1, mat_acessar(mat, 2, 2, &elemento), "verificar elemento contido na matriz");
  teste_verificar(t1, mat_acessar(mat, 3, 3, &elemento), "verificar elemento contido na matriz (erro: linha e coluna inválidas)");
  teste_verificar(t1, mat_acessar(mat, 2, -1, &elemento), "verificar elemento contido na matriz (erro: coluna inválida)");

  teste_verificar(t1, mat_linhas(mat) == 3, "verificar quantidade de linhas da matriz");
  teste_verificar(t1, mat_colunas(mat) == 3, "verificar quantidade de colunas da matriz");

  mat_imprimir(mat);

  mat_desalocar(&mat);
  teste_relatorio(t1);
  teste_desalocar(&t1);

  return 0;
}