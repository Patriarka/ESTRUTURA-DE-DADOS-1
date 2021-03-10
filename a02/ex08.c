#include <stdio.h>
#include <stdlib.h>

int* Intercalar_Vetores1(int* v1, int tam1, int* v2, int tam2){

  int tamResultante = tam1+tam2;
  int* vResultante = (int*) calloc(tamResultante, sizeof(int));
  
  int i, j, k;
  for(i = 0, j = 0, k = 0; k < tamResultante; k++){
    if(v2[j] <= v1[i] && j < tam2)
      vResultante[k] = v2[j++];
    else
      vResultante[k] = v1[i++];
  }

  return vResultante;
}

void Intercalar_Vetores2(int* v1, int tam1, int* v2, int tam2, int** vResultante){

  int tamResultante = tam1+tam2;
  *vResultante = (int*) calloc(tamResultante, sizeof(int));
  
  int i, j, k;
  for(i = 0, j = 0, k = 0; k < tamResultante; k++){
    if(v2[j] <= v1[i] && j < tam2)
      (*vResultante)[k] = v2[j++];
    else
      (*vResultante)[k] = v1[i++];
  }
}

void Vet_Imprimir(int* v, int qtdeElementos){

  int i;
  printf("[");
  for (i = 0; i < qtdeElementos; i++){
    printf("%d", v[i]);
    if(i < qtdeElementos-1) printf(",");
  }
  printf("]\n");
}

int main(){

  int* vResultante2;
  int v1[] = {6,7,8,9,10};
  int v2[] = {6,7,8,9};

  int* vResultante = Intercalar_Vetores1(v1, 5, v2, 4);

  Intercalar_Vetores2(v1, 5, v2, 4, &vResultante2);

  Vet_Imprimir(vResultante,5+4);
  Vet_Imprimir(vResultante2,5+4);

  free(vResultante);
  free(vResultante2);

  return 0;
}