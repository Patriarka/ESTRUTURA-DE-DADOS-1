#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct aluno{
  unsigned int codigo;
  char nome[50];
  float *notas;
  int qtdeNotas;
} Aluno;

double gerador(double min, double max){
  return min+(rand()/(RAND_MAX/(max-min)));
}

float* gerar_notas(int qtdeNotas){

  float* vetor_notas = (float*) malloc(qtdeNotas * sizeof(float));
  srand(time(NULL));
  for(int i = 0; i < qtdeNotas; i++){
    vetor_notas[i] = gerador(0, 10);
  }

  return vetor_notas;
}

Aluno* criar_aluno(int qtdeNotas){
  Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
  novo_aluno->notas = gerar_notas(qtdeNotas);
  return novo_aluno;
}

void aluno_destruir(Aluno* a){
  free(a);
  free(a->notas);
  a = NULL;
}

void imprimir_aluno(Aluno* a){
  printf("{");

  printf("%d,", a->codigo);
  printf("%s,", a->nome);
  printf("%d,", a->qtdeNotas);

  printf("[");
  for(int i = 0; i < a->qtdeNotas; i++){
    printf("%.2f", a->notas[i]);
    if(i != a->qtdeNotas-1) printf(",");
  }
  printf("]");

  printf("}\n");
}

int main(){

  Aluno* a1, *a2;

  a1 = criar_aluno(3);
  a1->codigo = 1;
  strcpy(a1->nome,"Alexander Hamilton");
  a1->qtdeNotas = 3;

  a2 = criar_aluno(5);
  a2->codigo = 2;
  strcpy(a2->nome,"Mary Poppins");
  a2->qtdeNotas = 5;

  imprimir_aluno(a1); 
  imprimir_aluno(a2); 

  aluno_destruir(a1);
  aluno_destruir(a2);

  return 0;
}
