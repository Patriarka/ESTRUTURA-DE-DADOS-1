#include <stdio.h>

void Capturar_Elementos(int m[3][3], int linhas, int colunas){
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      printf("Elemento[%d][%d]= ", i, j);
      scanf("%d", &m[i][j]);
    }
  }
}

void Imprimir_Matriz(int m[3][3], int linhas, int colunas){
  for(int i = 0; i < 3; i++){
    for(int j = 0;j < 3;j++)
      printf("%d ",m[i][j]);
    printf("\n");
  }
}

void Multiplicar_Elementos(int m[3][3], int linhas, int colunas, int mult){
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      m[i][j] *= mult;
    }
  }
}

int main(){

  int i, j, m[3][3];

  //captura os elementos
  Capturar_Elementos(m, 3, 3);

  //EXIBIR VALORES ORIGINAIS
  printf("\n::: Valores Originais :::\n");
  Imprimir_Matriz(m, 3, 3);

  //multiplica por 5
  Multiplicar_Elementos(m, 3, 3, 5);

  //EXIBIR VALORES MULTIPICADOS
  printf("\n::: Valores Multiplicados por 5:::\n");
  Imprimir_Matriz(m, 3, 3);

  return 0;
}