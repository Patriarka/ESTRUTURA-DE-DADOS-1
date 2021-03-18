#include <stdio.h>
#include <stdlib.h>

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

int* vetor_novoA(int tam, int valor){

  if(tam <= 0) return NULL;

  int* v = (int*) malloc(tam * sizeof(int));
  for(int i = 0; i < tam; i++)
    v[i] = valor;

  return v;
}

void vetor_novoB(int tam, int valor, int** v){

  if(tam <= 0) return;
  
  *v = (int*) malloc(tam * sizeof(int));
  for(int i = 0; i < tam; i++)
    (*v)[i] = valor;
}

int main(int argc, char *argv[]){

  int tam1 = atoi(argv[1]);
  int tam2 = atoi(argv[2]);

  int *v1, *v2;
  v1 = vetor_novoA(tam1, -1);
  vetor_novoB(tam2, 0, &v2);

  vet_imprimir(v1,tam1);
  vet_imprimir(v2,tam2);

  free(v1);
  free(v2);

  v1 = NULL;
  v2 = NULL;

  return 0;
}