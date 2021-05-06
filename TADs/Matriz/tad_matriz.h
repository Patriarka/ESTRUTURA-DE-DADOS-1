#ifndef _TAD_MATRIZ_H_
#define _TAD_MATRIZ_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********************************************
 * DADOS
********************************************/
typedef struct matriz Matriz;

/********************************************
 * OPERAÇÕES
********************************************/


/**
 * Cria e inicializa a Matriz de acordo com o tamanho especificado.
 * Parâmetro m: Quantidade de linhas
 * Parâmetro m: Quantidade de colunas
 * RETORNO: endereço da Matriz criada e inicializada na memória HEAP
 */
Matriz* mat_criar (int m, int n);

/**
 * Destroi a matriz especificada. A função desaloca o espaço e atribui NULL a variável que tinha a referência da Matriz
 * Parâmetro endMat: endereço da Matriz
 */
void mat_desalocar ( Matriz** endMat);

/**
 * Atribui um valor em uma célula da matriz.
 * Parâmetro mat: Endereço da Matriz
 * Parâmetro i: Número da linha
 * Parâmetro j: Número da coluna
 * Parâmetro v: Valor a ser atribuído na célula
 * RETORNO: true se a atribuição ocorreu com sucesso e false caso contrário
 */
bool mat_atribuir ( Matriz* mat, int i, int j, float v);

/**
 * Acessa o valor de uma célula da matriz
 * Parâmetro mat: Endereço da Matriz
 * Parâmetro i: Número da linha
 * Parâmetro j: Número da coluna
 * Parâmetro end: Endereço de memória na qual a função deve copiar o valor da célula solicitada.
 * RETORNO: true se a cópia foi realizada com sucesso e false caso contrário. 
 */
bool mat_acessar ( Matriz* mat, int i, int j, float* end);

/**
 * Devolve a quantidade de linhas contida na matriz
 * Parâmetro mat: Endereço da Matriz 
 * RETORNO: Número de linhas da matriz. 
 */
int mat_linhas ( Matriz* mat);

/**
 * Devolve a quantidade de linhas contida na matriz
 * Parâmetro mat: Endereço da Matriz 
 * RETORNO: Número de linhas da matriz. 
 */
int mat_colunas (Matriz* mat);

/**
 * Imprimir os elementos da matriz
 * Parâmetro mat: Endereço da matriz
 */
void mat_imprimir(Matriz* mat);

/**
 * Devolve uma cópia dos elementos de uma determinada linha da matriz
 * Parâmetro mat: Endereço da Matriz
 * Parâmetro linha: Número da linha
 * Parâmetro vetor: Endereço do vetor no qual a função deverá copiar os elementos da linha.
 * RETORNO: Quantidade de elementos copiados. Quantidade de elementos da linha. 
 */
int mat_vetLinha(Matriz* mat, int linha, float* vetor);

/**
 * Devolve uma cópia dos elementos de uma determinada linha da matriz
 * Parâmetro mat: Endereço da Matriz
 * Parâmetro coluna: Número da coluna
 * Parâmetro vetor: Endereço do vetor no qual a função deverá copiar os elementos da coluna.
 * RETORNO: Quantidade de elementos copiados. Quantidade de elementos da coluna. 
 */
int mat_vetColuna(Matriz* mat, int coluna, float* vetor);

/**
 * Devolve a posição (linha e coluna) do elemento especificado. Quando não encontrado a função devolve false
 * Parâmetro mat: Endereço da Matriz
 * Parâmetro elemento: Elemento a ser encontrado
 * Parâmetro endLinha: Se o elemento for encontrado, a função deverá armazenar a linha neste endereço de memória
 * Parâmetro endColuna: Se o elemento for encontrado, a função deverá armazenar a coluna neste endereço de memória
 * RETORNO: true quando o elemento for encontrado e false caso contrário. Quando o elemento for encontrado, a posição da linha e coluna serão copiadas nos endereços recebidos por parâmetro
 */
bool mat_posicao(Matriz* mat, float elemento, int* endLinha, int* endColuna);

#endif