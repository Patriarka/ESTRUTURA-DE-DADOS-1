#include "tad_matriz.h"

typedef struct matriz{
  float** m;
  int qtdeLinhas;
  int qtdeColunas;
} Matriz;

Matriz* mat_criar(int m, int n){
  
  Matriz* novaMatriz = (Matriz*) malloc(sizeof(Matriz));
  
  novaMatriz->qtdeLinhas = m;
  novaMatriz->qtdeColunas = n;  
  
  float** novaLinha = (float**) malloc(m*sizeof(float*));
  for(int i = 0; i < m; i++){
    float* novaColuna = (float*) calloc(n,sizeof(float));
    novaLinha[i] = novaColuna;
  }

  novaMatriz->m = novaLinha;

  return novaMatriz;
}

void mat_desalocar(Matriz** endMat){

  for(int i = 0; i < (*endMat)->qtdeLinhas; i++){
    free((*endMat)->m[i]);
  }
  free((*endMat)->m);
  free(*endMat);
  *endMat = NULL;
}

bool mat_atribuir(Matriz* mat, int i, int j, float v){
  
  if(!mat) return false;
  if(i < 0 || i >= mat->qtdeLinhas) return false;
  if(j < 0 || j >= mat->qtdeColunas) return false;
  
  mat->m[i][j] = v;

  return true;
}

bool mat_acessar(Matriz* mat, int i, int j, float* end){

  if(!mat) return false;
  if(i < 0 || i >= mat->qtdeLinhas) return false;
  if(j < 0 || j >= mat->qtdeColunas) return false;

  *end = mat->m[i][j];

  return true;
}

int mat_linhas(Matriz* mat){
  if(!mat) return -1;
  return mat->qtdeLinhas;
}

int mat_colunas(Matriz* mat){
  if(!mat) return -1;
  return mat->qtdeColunas;
}

void mat_imprimir(Matriz* mat){

  if(!mat) return;

  for(int i = 0; i < mat->qtdeLinhas; i++){
    for(int j = 0; j < mat->qtdeColunas; j++){
      printf("%f", mat->m[i][j]);
      if(j != mat->qtdeColunas - 1) printf("|");
    }
    printf("\n");
  }
}

int mat_vetLinha(Matriz* mat, int linha, float* vetor){

  if(!mat) return false;
  if(linha >= mat->qtdeLinhas || linha < 0) return -1;
  
  for(int j = 0; j < mat->qtdeColunas; j++){
    vetor[j] = mat->m[linha][j];
  }

  return mat->qtdeColunas;
}

int mat_vetColuna(Matriz* mat, int coluna, float* vetor){
  
  if(!mat) return false;
  if(coluna >= mat->qtdeLinhas || coluna < 0) return -1;
  
  for(int i = 0; i < mat->qtdeLinhas; i++){
    vetor[i] = mat->m[i][coluna];
  }

  return mat->qtdeLinhas;
}

bool mat_posicao(Matriz* mat, float elemento, int* endLinha, int* endColuna){

  if(!mat) return false;

  for(int i = 0; i < mat->qtdeLinhas; i++){
    for(int j = 0; j < mat->qtdeColunas; j++){
      if(elemento == mat->m[i][j]){
        *endLinha = i;
        *endColuna = j;
        return true;
      }
    }
  }

  return false;
}

