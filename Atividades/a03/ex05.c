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

void vetor_incrementa(int* v, int tam){

  if(!v) return;
  if(tam <= 0) return;

  for(int i = 0; i < tam; i++){
    v[i] += 1;
  }
}

int main(){

  int v1[5] = {10,20,30,40,50};
  vetor_incrementa(v1, 5); // [11,21,31,41,51]
  vet_imprimir(v1, 5);

  return 0;
}