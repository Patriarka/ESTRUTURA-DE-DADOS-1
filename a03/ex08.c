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

Aluno* criar_aluno(){
  Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
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

  float* v_notas, *v_notas2;

  int qtdeNotas1 = 3;
  int qtdeNotas2 = 5;

  v_notas = gerar_notas(qtdeNotas1);
  v_notas2 = gerar_notas(qtdeNotas2);

  a1 = criar_aluno();
  a1->codigo = 1;
  strcpy(a1->nome,"Alexander Hamilton");
  a1->notas = v_notas;
  a1->qtdeNotas = qtdeNotas1;

  a2 = criar_aluno();
  a2->codigo = 2;
  strcpy(a2->nome,"Mary Poppins");
  a2->notas = v_notas2;
  a2->qtdeNotas = qtdeNotas2;

  imprimir_aluno(a1); 
  imprimir_aluno(a2); 

  aluno_destruir(a1);
  aluno_destruir(a2);

  return 0;
}