#include <stdio.h>

void Capturar_Elementos(int* p, int linhas, int colunas){
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      printf("Elemento[%d][%d]= ", i, j);
      scanf("%d", (p+(i*colunas)+j));
    }
  }
}

void Imprimir_Matriz(int* p, int linhas, int colunas){
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++)
      printf("%d ", *(p+(i*colunas)+j));
    printf("\n");
  }
}

void Multiplicar_Elementos(int* p, int linhas, int colunas, int mult){
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      *(p+(i*colunas)+j) *= mult;
    }
  }
}

int main(){

  int m[3][3];

  //captura os elementos
  Capturar_Elementos(*m, 3, 3);

  // //EXIBIR VALORES ORIGINAIS
  printf("\n::: Valores Originais :::\n");
  Imprimir_Matriz(*m, 3, 3);
 
  //multiplica por 5
  Multiplicar_Elementos(*m, 3, 3, 5);

  //EXIBIR VALORES MULTIPICADOS
  printf("\n::: Valores Multiplicados por 5:::\n");
  Imprimir_Matriz(*m, 3, 3);

  return 0;
}
