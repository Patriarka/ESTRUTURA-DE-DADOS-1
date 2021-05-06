#include "pilha.h"

/**************************************
* DADOS
**************************************/
typedef struct no
{
  TipoElemento dado;
  struct no *prox;
} No;

struct _pilha
{
  No *topo;
  int qtdeElementos;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções
Pilha *pilha_criar()
{
  Pilha *novaPilha = (Pilha *) malloc(sizeof(Pilha));
  novaPilha->qtdeElementos = 0;
  novaPilha->topo = NULL;
}

static void no_destruir(No *no_base)
{
  if (no_base == NULL)
    return;
  no_destruir(no_base->prox);
  free(no_base);
}

void pilha_destruir(Pilha **endereco)
{
  no_destruir((*endereco)->topo);
  free(*endereco);
  *endereco = NULL;
}

static No *no_criar(TipoElemento dado)
{
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->dado = dado;
  novoNo->prox = NULL;

  return novoNo;
}

bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{

  if (!p)
    return false;

  No *novoNo = no_criar(elemento);

  if (p->qtdeElementos > 0)
    novoNo->prox = p->topo;

  p->topo = novoNo;

  p->qtdeElementos++;

  return true;
}

bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
  if (pilha_vazia(p) == true)
    return false;

  *saida = p->topo->dado;
  if(p->qtdeElementos > 1){
    No* aux = p->topo->prox;
    free(p->topo);
    p->topo = aux;
  } else {
    free(p->topo);
    p->topo = NULL;
  }

  p->qtdeElementos--;

  return true;
}

bool pilha_topo(Pilha *p, TipoElemento *saida)
{
  if (!p)
    return false;
  *saida = p->topo->dado;

  return true;
}

bool pilha_vazia(Pilha *p)
{
  if (p->qtdeElementos == 0)
    return true;
  else
    return false;
}

void pilha_imprimir(Pilha *p)
{
  No *aux = p->topo;

  printf("[");
  while (aux != NULL)
  {
    printf("%d", aux->dado);
    if (aux->prox != NULL)
      printf(",");

    aux = aux->prox;
  }
  printf("]\n");
}

int pilha_tamanho(Pilha *p)
{
  return p->qtdeElementos;
}

Pilha *pilha_clone(Pilha *p)
{
  Pilha *clone = pilha_criar();
  pilha_inverter(p);
  No* aux = p->topo;
  while(aux != NULL){
    pilha_empilhar(clone,aux->dado);
    aux = aux->prox;
  }
  clone->qtdeElementos = p->qtdeElementos;
  pilha_inverter(p);

  return clone;
}

void pilha_inverter(Pilha *p)
{
  TipoElemento saida;
  int tamVetor = p->qtdeElementos;
  TipoElemento vetor[tamVetor];
  int i = 0;
  No *aux = p->topo;
  while (aux != NULL)
  {
    aux = aux->prox;
    pilha_desempilhar(p,&saida);
    vetor[i++] = saida;
  }
  pilha_empilharTodos(p, vetor, tamVetor);
}

bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor)
{
  if (!p)
    return false;
  if (!vetor)
    return false;
  for (int i = 0; i < tamVetor; i++)
    pilha_empilhar(p, vetor[i]);

  return true;
}

bool pilha_toString(Pilha *f, char *str)
{
  if (!f)
    return false;

  int j;
  int posicao = 0;
  char strAux[20];

  str[posicao++] = '[';

  No *aux = f->topo;
  while (aux != NULL)
  {
    j = 0;

    sprintf(&strAux[j], "%d", aux->dado);

    while (strAux[j] != '\0')
      str[posicao++] = strAux[j++];
    if (aux->prox != NULL)
      str[posicao++] = ',';
    aux = aux->prox;
  }
  str[posicao++] = ']';
  str[posicao++] = '\0';

  return true;
}