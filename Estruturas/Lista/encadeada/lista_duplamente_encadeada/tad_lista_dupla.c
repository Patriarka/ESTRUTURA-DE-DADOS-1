#include "tad_lista_dupla.h"

/**************************************
* DADOS
**************************************/
typedef struct no
{
	TipoElemento dado;
	struct no *ant;
	struct no *prox;
} No;

struct lista
{
	No *inicio;
	No *fim;
	int qtde;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/

Lista *lista_criar()
{
	Lista *novaLista = (Lista *)malloc(sizeof(Lista));

	novaLista->inicio = NULL;
	novaLista->fim = NULL;
	novaLista->qtde = 0;

	return novaLista;
}

static No* no_criar(TipoElemento dado)
{
	No* novoNo = (No*) malloc(sizeof(No));
	
	novoNo->ant = NULL;
	novoNo->prox = NULL;
	novoNo->dado = dado;

	return novoNo;
}

static void no_destruir(No *no)
{
	if (no == NULL)
		return;
	no_destruir(no->prox);
	free(no);
}

static bool lista_ehValida(Lista *l)
{
	if (l == NULL)
		return false;
	return true;
}

void lista_destruir(Lista **endLista)
{
	if (!lista_ehValida(*endLista))
		return;

	no_destruir((*endLista)->inicio);
	free(*endLista);
	*endLista = NULL;
}

bool lista_anexar(Lista *l, TipoElemento elemento)
{
	if (!lista_ehValida(l))
		return false;

	lista_inserir(l,elemento,l->qtde);

	return true;
}

bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{
	if (!lista_ehValida(l))
		return false;
	if (posicao < 0 || posicao > l->qtde) 
		return false;

	No* novoNo = no_criar(elemento);

	if (!lista_vazia(l)){
		if (posicao == 0){
			novoNo->prox = l->inicio;
			l->inicio->ant = novoNo;
			l->inicio = novoNo;
		} else if (posicao == l->qtde){
			novoNo->ant = l->fim;
			l->fim->prox = novoNo;
			l->fim = novoNo;
		} else {
			No* noAux = l->inicio;
			for(int i = 0; i < posicao; i++)
				noAux = noAux->prox;
			
			noAux->ant->prox = novoNo;
			novoNo->ant = noAux->ant;

			noAux->ant = novoNo;
			novoNo->prox = noAux;
		}
	} else {
		l->inicio = novoNo; 
		l->fim = novoNo;
	}	

	l->qtde++;

	return true;
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
{
	if (!lista_ehValida(l))
		return false;
	if (posicao < 0 || posicao >= l->qtde) 
		return false;
	if (lista_vazia(l))
		return false;

	lista_buscar(l,posicao,endereco);

	if (l->qtde == 1){
		free(l->inicio);
		l->inicio = NULL;
		l->fim = NULL;
	} else {
		if (posicao == 0){
			l->inicio->prox->ant = NULL;
			free(l->inicio);
			l->inicio = l->inicio->prox;
		} else if (posicao == l->qtde-1) {
			l->fim->ant->prox = NULL;
			free(l->fim);
			l->fim = l->fim->ant;
		} else {
			No* noAux = l->inicio;
			for(int i = 0; i < posicao; i++)
				noAux = noAux->prox;
			noAux->ant->prox = noAux->prox;
			noAux->prox->ant = noAux->ant;
			free(noAux);
		}
	}
	
	l->qtde--;

	return true;
}

int lista_removerElemento(Lista *l, TipoElemento elemento)
{
	if (!lista_ehValida(l))
		return -1;
	if (!lista_contem(l,elemento))
		return -1;

	int posicao = lista_posicao(l,elemento);
	if (posicao == -1) return -1;
	
	TipoElemento removido;
	if (!lista_removerPosicao(l,posicao,&removido))
		return -1;

	return posicao;
}

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento)
{
	if (!lista_ehValida(l))
		return false;
	
	No* noAux = l->inicio;
	for(int i = 0; i < posicao; i++)
		noAux = noAux->prox;
	noAux->dado = novoElemento;

	return true;
}

bool lista_vazia(Lista *l)
{
	if (!lista_ehValida(l))
		return false;

	if (l->qtde == 0)
		return true;
	else
		return false;
}

int lista_posicao(Lista *l, TipoElemento elemento)
{
	if (!lista_ehValida(l))
		return -1;

	int i = 0;
	No *no_aux = l->inicio;
	while (i < l->qtde)
	{
		if (no_aux->dado == elemento)
			return i;
		no_aux = no_aux->prox;
		i++;
	}
	return -1;
}

bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco)
{
	if (!lista_ehValida(l))
		return false;

	int i = 0;
	No *no_aux = l->inicio;
	while (no_aux != NULL)
	{
		if (i == posicao){
			*endereco = no_aux->dado;
			return true;
		}
		no_aux = no_aux->prox;
		i++;
	}

	return false;
}

bool lista_contem(Lista *l, TipoElemento elemento)
{
	if (!lista_ehValida(l))
		return false;
	No *no_aux = l->inicio;
	while (no_aux != NULL)
	{
		if (no_aux->dado == elemento)
			return true;
		no_aux = no_aux->prox;
	}
	return false;
}

int lista_tamanho(Lista *l)
{
	if (!lista_ehValida(l))
		return -1;
	return l->qtde;
}

bool lista_toString(Lista *l, char *str)
{
	if (!lista_ehValida(l))
		return false;

	int posicao = 0;
	No *no_aux = l->inicio;

	str[posicao++] = '[';
	while (no_aux != NULL)
	{
		sprintf(&str[posicao], FORMATO, no_aux->dado);
		posicao = strlen(str);
		no_aux = no_aux->prox;
		if (no_aux != NULL)
			str[posicao++] = ',';
	}
	str[posicao++] = ']';
	str[posicao++] = '\0';

	return true;
}

void lista_imprimir(Lista *l)
{
	if (!lista_ehValida(l))
		return;

	No *no_aux = l->inicio;
	printf("[");
	while (no_aux != NULL)
	{
		printf(FORMATO, no_aux->dado);
		if (no_aux->prox != NULL) printf(",");
		no_aux = no_aux->prox;
	}
	printf("]\n");
}
