#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{
  unsigned int codigo;
  char nome[50];
  float preco;
} Produto;

Produto* produto_criar(unsigned int codigo, char* nome, float preco){

  Produto* novo_produto = (Produto*) malloc(sizeof(Produto));
  
  novo_produto->codigo = codigo;
  strcpy(novo_produto->nome, nome);
  novo_produto->preco = preco;

  return novo_produto;
}

void imprimir_produto(Produto* produto){
  printf("{");
  printf("%u,", produto->codigo);
  printf("%s,", produto->nome);
  printf("%.2f", produto->preco);
  printf("}\n");
}

int main(){

  Produto* p1, *p2, *p3;

  p1 = produto_criar(1, "Blade runner 2049", 69.99);
  imprimir_produto(p1);

  p2 = produto_criar(2, "Whiplash", 49.99);
  imprimir_produto(p2);
  
  p3 = produto_criar(3, "Mary Poppins", 79.99);
  imprimir_produto(p3);

  free(p1);
  free(p2);
  free(p3);

  p1 = NULL;
  p2 = NULL;
  p3 = NULL;

  return 0;
}