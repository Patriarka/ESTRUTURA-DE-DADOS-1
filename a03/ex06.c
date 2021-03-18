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

int vetor_dobraTamanho(int** v, int tam){

  int novoTamanho = tam*2;

  int* vetor_dobro = (int*) calloc(novoTamanho, sizeof(int));
  for(int i = 0; i < tam; i++)
    vetor_dobro[i] = (*v)[i];
  free(*v);
  *v = vetor_dobro;

  return novoTamanho;
}

int main(){
  
  int* v = (int*) calloc(3, sizeof(int));
  v[0] = 2;
  v[1] = 4;
  v[2] = 6;

  int novoTamanho = vetor_dobraTamanho(&v,3);
  vet_imprimir(v,novoTamanho);
  //Resultado esperado
  // [2,4,6,0,0,0]

  return 0;
}