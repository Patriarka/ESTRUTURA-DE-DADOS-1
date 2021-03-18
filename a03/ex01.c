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

int main(int argc, char *argv[]){

  int tam = atoi(argv[1]);

  int* v = (int*) malloc(tam * sizeof(int));

  for(int i = 0; i < tam; i++)
    v[i] = i+1;

  vet_imprimir(v,tam);
  vet_imprimir(v,-tam);
  vet_imprimir(v,0);

  free(v);
  v = NULL;

  return 0;
}