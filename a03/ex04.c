#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int* vetor_aleatorio(int tam_vetor){

  if(tam_vetor < 0) return NULL;

  int* novo_vetor = (int*) calloc(tam_vetor, sizeof(int));

  srand (time(NULL));
  for(int i = 0; i < tam_vetor; i++){
    novo_vetor[i] = rand() % 1000;
  }

  return novo_vetor;
}

int main(){

  int *v1 = vetor_aleatorio(10);
  int *v2 = vetor_aleatorio(100);

  vet_imprimir(v1, 10);
  vet_imprimir(v2, 100);

  free(v1);
  free(v2);

  v1 = NULL;
  v2 = NULL;

  return 0;
}