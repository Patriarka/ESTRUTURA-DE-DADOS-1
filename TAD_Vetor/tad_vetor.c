#include "tad_vetor.h"

struct vetor{
  int* vetor;
  int tamVetor;
  int qtdeElementos;
};

static void aumentar_vetor(Vetor* v){

  v->tamVetor = v->tamVetor*2;

  int* novoVetor = (int*) calloc(v->tamVetor,sizeof(int));
  memcpy(novoVetor,v->vetor,v->qtdeElementos*sizeof(int));
  free(v->vetor);

  v->vetor = novoVetor;
}

static void diminuir_vetor(Vetor* v){

  v->tamVetor = v->tamVetor/2;

  int* novoVetor = (int*) calloc(v->tamVetor,sizeof(int));
  memcpy(novoVetor,v->vetor,v->qtdeElementos*sizeof(int));
  free(v->vetor);

  v->vetor = novoVetor;
}

Vetor* vet_criar(int tam){

  if(tam <= 0) return NULL;  

  Vetor* novoVetor = (Vetor*) malloc(sizeof(Vetor));

  novoVetor->vetor = (int*) calloc(tam,sizeof(int));

  novoVetor->tamVetor = tam;
  novoVetor->qtdeElementos = 0;

  return novoVetor;
}

bool vet_anexar(Vetor* v, int elemento){

  if(!v) return false;
  if(v->qtdeElementos == v->tamVetor) aumentar_vetor(v);

  v->vetor[v->qtdeElementos++] = elemento;

  return true;
}

bool vet_inserir(Vetor* v, int elemento, int posicao){

  if(!v) return false;  
  if(posicao < 0 || posicao > v->qtdeElementos+1) return false;
  if(v->qtdeElementos == v->tamVetor) aumentar_vetor(v);

  if(posicao == v->qtdeElementos+1) { 
    vet_anexar(v, elemento);
    return true;

  } else if(posicao == 0){
    int* auxiliar = (int*) calloc(v->qtdeElementos,sizeof(int));
    int tamanhoVetorCopia = v->qtdeElementos*sizeof(int);

    memcpy(auxiliar,v->vetor,tamanhoVetorCopia);
    memcpy(&v->vetor[1],auxiliar,tamanhoVetorCopia);
    
    v->vetor[posicao] = elemento;
    free(auxiliar);

  } else { 
    int* auxiliar = (int*) calloc(v->qtdeElementos-posicao,sizeof(int));

    int tamanhoVetorCopia = (v->qtdeElementos-posicao)*sizeof(int);
    memcpy(auxiliar,&v->vetor[posicao],tamanhoVetorCopia);
    memcpy(&v->vetor[posicao+1],auxiliar,tamanhoVetorCopia);

    v->vetor[posicao] = elemento;
    free(auxiliar);
  } 
  v->qtdeElementos++; 

  return true;
}

int vet_tamanho_alocado(Vetor* v){
  if(!v) return -1;
  return v->tamVetor;
}

int vet_tamanho(Vetor* v){
  if(!v) return -1;
  return v->qtdeElementos;
}

bool vet_elemento(Vetor* v, int posicao, int* saida){
  
  if(!v) return false;
  if(posicao < 0) return false;
  if(posicao > v->qtdeElementos) return false;

  *saida = v->vetor[posicao];

  return true;
}

bool vet_substituir(Vetor* v, int posicao, int novoElemento){

  if(!v) return false;
  if(posicao < 0 || posicao >= v->qtdeElementos) return false;
  
  v->vetor[posicao] = novoElemento;

  return true;
}

bool vet_removerPosicao(Vetor* v, int posicao, int* endereco){

  if(!v) return false;
  if(v->qtdeElementos <= 0) return false;
  if(posicao < 0 || posicao >= v->qtdeElementos) return false;
  if(v->qtdeElementos <= ((float)45/100*v->tamVetor)) diminuir_vetor(v);

  *endereco = v->vetor[posicao];

  for(int i = posicao; i < v->qtdeElementos; i++)
    v->vetor[i] = v->vetor[i+1];

  v->qtdeElementos--;

  return true;
} 

int vet_removerElemento(Vetor* v, int elemento){

  if(!v) return -1;
  if(v->qtdeElementos <= ((float)45/100*v->tamVetor)) diminuir_vetor(v);

  int removido;
  for(int i = 0; i < v->qtdeElementos; i++){
    if(v->vetor[i] == elemento){ 
      vet_removerPosicao(v,i,&removido);
      return i;
    }
  }
  return -1;
}

int vet_posicao(Vetor* v, int elemento){
  
  if(!v) return -1;

  int i = 0;
  for(i = 0; i < v->qtdeElementos; i++){
    if(v->vetor[i] == elemento) return i;
  }

  return -1;
}

int vet_imprimir(Vetor* v){

  int i = 0;
  printf("[");
  while(i < v->qtdeElementos){
    printf("%d", v->vetor[i++]);
    if(i != v->qtdeElementos) printf(",");
  }
  printf("]\n");
}

void vet_desalocar(Vetor* v){
  if(!v) return;
  free(v->vetor);
  free(v);
}

bool vet_toString(Vetor* v, char* enderecoString){

  if(!v) return false;
  if(v->qtdeElementos <= 0) return false;
    
  int posicao = 0;
  int tamVetorStr = (v->qtdeElementos*2)+1; 
  char strAuxiliar[tamVetorStr+1];

  enderecoString[posicao++] = '[';
  for(int i = 0; i < v->qtdeElementos; i++){
    int j = 0;
    sprintf(&strAuxiliar[j], "%d", v->vetor[i]);
    while(strAuxiliar[j] != '\0'){
      enderecoString[posicao++] = strAuxiliar[j];
      j++;
    }
    if(i != v->qtdeElementos-1) enderecoString[posicao++] = ',';
  }
  enderecoString[posicao++] = ']';
  enderecoString[posicao] = '\0';
  
  return true;
} 






