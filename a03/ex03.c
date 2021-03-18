#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vet_imprimir(int* v, int tam){
  
  if(!v) return;
  if(tam < 0) return;

  printf("[");
  for(int i = 0; i < tam; i++){
    printf("%d", v[i]);
    if(i % tam != tam-1) printf(",");
  }
  printf("]\n");
}

void atribuir_crescente(int* v, int tam){
  for(int i = 0; i < tam; i++){
    v[i] = i+1;
  }
}

int* clonar_vetorA(int* v, int tam){

  int* clone = (int*) malloc(tam * sizeof(int));
  memcpy(clone, v, tam * sizeof(int));

  return clone;
}

void clonar_vetorB(int* v, int tam, int** clone){
  *clone = (int*) malloc(tam * sizeof(int));
  for(int i = 0; i < tam; i++)
    (*clone)[i] = v[i];
}

int main(int argc, char *argv[]){

  int tam = atoi(argv[1]);
  
  int* v = (int*) malloc(tam * sizeof(int));
  int* v2 = (int*) malloc(tam * sizeof(int));
  int* clone2;

  atribuir_crescente(v,tam);
  atribuir_crescente(v2,tam);

  int* clone1 = clonar_vetorA(v,tam);

  vet_imprimir(clone1, tam);

  clonar_vetorB(v2,tam,&clone2);
  vet_imprimir(clone2, tam);

  free(v);
  v = NULL;

  return 0;
}