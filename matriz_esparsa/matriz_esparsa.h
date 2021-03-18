#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int linha;
  int coluna;
  int valor;
  struct node* direita;
  struct node* baixo;
  struct node* esquerda;
  struct node* cima;
} Node;

typedef struct{
  Node** linhas;
  Node** colunas; 
  int numLinhas; 
  int numColunas; 
} Matriz;

Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas);
int matriz_atribuir(Matriz* m, int linha, int coluna, int valor);
int matriz_acessar(Matriz* m, int linha, int coluna);
void matriz_imprimir(Matriz* m);

static Node* node_criar(int linha, int coluna, int valor){

  Node* novoNo = (Node*) malloc(sizeof(Node));
  
  novoNo->linha = linha;
  novoNo->coluna = coluna;
  novoNo->valor = valor;

  novoNo->cima = NULL;
  novoNo->direita = NULL;
  novoNo->baixo = NULL;
  novoNo->esquerda = NULL;

  return novoNo;
}

Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas){

  Matriz* novaMatriz = (Matriz*) malloc(sizeof(Matriz));

  novaMatriz->numLinhas = qtdeLinhas;
  novaMatriz->numColunas = qtdeColunas;

  novaMatriz->linhas = (Node**) malloc(novaMatriz->numLinhas * sizeof(Node*));
  novaMatriz->colunas = (Node**) malloc(novaMatriz->numColunas * sizeof(Node*));

  for(int i = 0; i < qtdeLinhas; i++){
    Node* sentinela_linha = node_criar(i,-1,-1);

    novaMatriz->linhas[i] = sentinela_linha;

    sentinela_linha->esquerda = sentinela_linha->baixo;
    sentinela_linha->direita = sentinela_linha->cima;
  }

  for(int i = 0; i < qtdeColunas; i++){
    Node* sentinela_coluna = node_criar(-1,i,-1);

    novaMatriz->colunas[i] = sentinela_coluna;

    sentinela_coluna->cima = sentinela_coluna->direita;
    sentinela_coluna->baixo = sentinela_coluna->esquerda;
  }

  return novaMatriz;
}

int matriz_atribuir(Matriz* m, int linha, int coluna, int valor){

  if(!m) return 0;
  if(linha >= m->numLinhas 
    || coluna >= m->numColunas) 
      return 0;

  if(matriz_acessar(m, linha, coluna) == -1){
    Node* novoNo = node_criar(linha, coluna, valor);
    novoNo->valor = valor;
  }

  return 1;
}

int matriz_acessar(Matriz* m, int linha, int coluna){
  
  if(!m) return -1;
  if(linha >= m->numLinhas
    || coluna >= m->numColunas)
      return 0;

  Node* sentinela_linha = m->linhas[linha];
  Node* sentinela_coluna = m->colunas[coluna]; 

  Node* aux_linha = sentinela_linha;
  Node* aux_coluna = sentinela_coluna;

  while(aux_linha->direita->linha != linha){
    
  } 

  // while(sentinela_linha->direita->coluna != coluna)

  // return aux_linha->valor;
}

void matriz_desalocar(Matriz* m){

  Node* aux = NULL;
  for(int i = 0; i < m->numLinhas; i++){
    aux = m->linhas[i]->direita;
    if(!aux) break;
    while(aux != m->linhas[i]){
      Node* desalocar = aux;
      aux = aux->direita;
      free(desalocar);
    }
  }

  for(int i = 0; i < m->numLinhas; i++)
    free(m->linhas[i]);

  for(int i = 0; i < m->numColunas; i++)
    free(m->colunas[i]);

  free(m->linhas);
  free(m->colunas);
  free(m);
}
