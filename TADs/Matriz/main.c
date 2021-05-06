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
  teste_verificar(t1, mat_acessar(mat, 3, 3, &elemento) == false, "verificar elemento contido na matriz (erro: linha e coluna inválidas)");
  teste_verificar(t1, mat_acessar(mat, 2, -1, &elemento) == false, "verificar elemento contido na matriz (erro: coluna inválida)");

  teste_verificar(t1, mat_linhas(mat) == 3, "verificar quantidade de linhas da matriz");
  teste_verificar(t1, mat_colunas(mat) == 3, "verificar quantidade de colunas da matriz");

  mat_imprimir(mat);

  float* vetor_linhas = (float*) malloc(mat_linhas(mat)*sizeof(float));
  teste_verificar(t1, mat_vetLinha(mat, 0, vetor_linhas) == mat_linhas(mat), "verificar linha da matriz");
  free(vetor_linhas);

  float* vetor_colunas = (float*) malloc(mat_colunas(mat)*sizeof(float));
  teste_verificar(t1, mat_vetColuna(mat, 1, vetor_colunas) == mat_colunas(mat), "verificar coluna da matriz");
  free(vetor_colunas);
  
  int endLinha, endColuna;
  teste_verificar(t1, mat_posicao(mat, 1.25, &endLinha, &endColuna), "verificar posição do elemento na matriz");
  teste_verificar(t1, endColuna == 1 && endLinha == 1, "verificar inserção da posição do elemento nas variáveis passadas");

  mat_desalocar(&mat);
  teste_relatorio(t1);
  teste_desalocar(&t1);

  return 0;
}