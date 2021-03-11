#include <stdio.h>
#include <stdlib.h>

int* Intercalar_Vetores1(int* v1, int tam1, int* v2, int tam2, int* vResultante){

  int tamResultante = tam1+tam2;
  
  int i, j, k;
  for(i = 0, j = 0, k = 0; k < tamResultante; k++){
    if(v2[j] <= v1[i] && j < tam2)
      vResultante[k] = v2[j++];
    else
      vResultante[k] = v1[i++];
  }

  return vResultante;
}

void Intercalar_Vetores2(int* v1, int tam1, int* v2, int tam2, int* vResultante){

  int tamResultante = tam1+tam2;
  
  int i, j, k;
  for(i = 0, j = 0, k = 0; k < tamResultante; k++){
    if(v2[j] <= v1[i] && j < tam2)
      vResultante[k] = v2[j++];
    else
      vResultante[k] = v1[i++];
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

  int vResultante[9]; 
  int* vResultante2;
  int v1[] = {6,7,8,9,10};
  int v2[] = {6,7,8,9};

  int* resultante = Intercalar_Vetores1(v1, 5, v2, 4, vResultante);
  Vet_Imprimir(resultante,9);

  Intercalar_Vetores2(v1, 5, v2, 4, vResultante);
  Vet_Imprimir(vResultante,9);

  int v3[] = {1,2,3,4,5};
  int v4[] = {1,2,3,4};

  resultante = Intercalar_Vetores1(v3, 5, v4, 4, vResultante);
  Vet_Imprimir(resultante,9);

  Intercalar_Vetores2(v3, 5, v4, 4, vResultante);
  Vet_Imprimir(vResultante,9);

  int v5[] = {-5,-1,2,3,4};
  int v6[] = {-3,1,2,4};

  resultante = Intercalar_Vetores1(v5, 5, v6, 4, vResultante);
  Vet_Imprimir(resultante,9);

  Intercalar_Vetores2(v5, 5, v6, 4, vResultante);
  Vet_Imprimir(vResultante,9); 

  return 0;
}
