#include <stdio.h>

int Maior_Elemento1(int* v, int qtdeElementos){
  
  if(!v || qtdeElementos < 0) return -1;

  int maior = 0;
  for(int i = 1; i < qtdeElementos; i++)
    if(v[i] > v[maior]) maior = i;
  
  return v[maior];
}

void Maior_Elemento2(int* v, int qtdeElementos, int* maior){

  if(!v || qtdeElementos < 0){
    *maior = -1;
    return;
  } 
  
  *maior = 0;
  for(int i = 1; i < qtdeElementos; i++)
    if(v[i] > v[*maior]) *maior = i;
  *maior = v[*maior];
}

int main(){

  int maior;
  int v[] = {1,2,7,4,5};

  printf("Maior: %d\n",Maior_Elemento1(v,-5));
  printf("Maior: %d\n",Maior_Elemento1(v,5));

  Maior_Elemento2(v,5,&maior);
  printf("Maior: %d\n", maior);
  Maior_Elemento2(v,-5,&maior);
  printf("Maior: %d\n", maior);

  return 0;
}