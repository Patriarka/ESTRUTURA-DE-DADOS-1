#include "tad_teste.h"

Teste* teste_criar(char* descricao){

  Teste* novo_teste = (Teste*) malloc(sizeof(Teste));
  novo_teste->nomeTeste = (char*) calloc(strlen(descricao)+1, sizeof(char));
  
  strcpy(novo_teste->nomeTeste, descricao);

  return novo_teste;
}

void teste_verificar(Teste* t, int condicao, char *mensagem){

  if(condicao == true){
    printf("[OK]: %s\n", mensagem);
    t->qtdeAcertos++;
  } else {
    printf("Erro: %s\n", mensagem);
    t->qtdeErros++;
  }

  t->qtdeTestes++;
}

void teste_relatorio(Teste* t){

  printf("----------------------------------------------------\n");
  printf("%s\n", t->nomeTeste);
  printf("----------------------------------------------------\n");

  printf("Total    = %d\n", t->qtdeTestes);
  printf("Passaram    = %d\n", t->qtdeAcertos);
  printf("Falharam    = %d\n", t->qtdeErros);
}

void teste_desalocar(Teste** t){

  free((*t)->nomeTeste);
  (*t)->nomeTeste = NULL;
  free(*t);
  *t = NULL;
}