#include <stdio.h>

int Soma_Vetor1(int* v, int qtdeElementos){

  int resultado = 0;

  if(!v || qtdeElementos < 0) return -1;
  for(int i = 0; i < qtdeElementos; i++)
    resultado += v[i];

  return resultado;
}

void Soma_Vetor2(int* v, int qtdeElementos, int* resultado){

  *resultado = 0;

  if(!v || qtdeElementos < 0) return;
  for(int i = 0; i < qtdeElementos; i++)
    *resultado += v[i];
}

int main(){

  int resultado;
  int v[] = {1,2,3,4,5};

  printf("%d\n", Soma_Vetor1(v, 5));
  printf("%d\n", Soma_Vetor1(v, -5));

  Soma_Vetor2(v,5,&resultado);
  printf("%d\n", resultado);

  Soma_Vetor2(v,-5,&resultado);
  printf("%d\n", resultado);

  return 0;
}