#include <stdio.h>

void Multiplicar_Vetor(int* v, int qtdeElementos, int mult){
  for(int i = 0; i < qtdeElementos; i++)
    v[i] *= mult;
}

void Inicializar_Vetor(int* v, int qtdeElementos, int valor){
  for (int i = 0; i < qtdeElementos; i++)
    v[i] = valor;
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

  int vet1[10];
  int vet2[5];

  // Inicializa o vetor com o valor 1
  Inicializar_Vetor(vet1, 10, 1);

  // Imprime o resultado da inicialização
  Vet_Imprimir(vet1, 10);

  // Multiplica todos os valores por -1
  Multiplicar_Vetor(vet1, 10, -1);
  
  // Imprime o resultado da multiplicação
  Vet_Imprimir(vet1, 10);
  
  // Inicializa o vetor VET2 com o valor 20
  Inicializar_Vetor(vet2, 5, 20);

  // Imprime o resultado da inicialização
  Vet_Imprimir(vet2, 5);

  // Multiplica todos os valores por 2
  Multiplicar_Vetor(vet2, 5, 2);

  // Imprime o resultado da inicialização
  Vet_Imprimir(vet2, 5);
}