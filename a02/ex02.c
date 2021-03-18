#include <stdio.h>
#include <math.h>

int Conta_digitos(int N){ 
  
    int cont = 1;

    if(N >= 10){
      N = N/10;
      cont = cont + Conta_digitos(N);
    }

    return cont;
}

int Ordem_Inversa1(int num){
  
  if(num < 0) return -1;
  if(num >= 0 && num < 10) return num;

  int resultado = 0, aux1 = 0, mult = 1;
  int divisor = pow(10, Conta_digitos(num)-1);

  while(divisor >= 1){
    aux1 = num / divisor;
    num = num % divisor;
    resultado += aux1*mult;

    if(divisor == 1) 
      resultado += num*mult;

    mult *= 10;
    divisor /= 10;
  }

  return resultado;
}

void Ordem_Inversa2(int num, int* resultado){

  if(num < 0){
    *resultado = -1;
    return;
  } if(num >= 0 && num < 10){
    *resultado = num;
    return;
  } 

  *resultado = 0;
  int aux1 = 0, mult = 1;
  int divisor = pow(10, Conta_digitos(num)-1);

  while(divisor >= 1){
    aux1 = num / divisor;
    num = num % divisor;
    *resultado += aux1*mult;

    if(divisor == 1) 
      *resultado += num*mult;

    mult *= 10;
    divisor /= 10;
  }
}

int main(){

  int inverso;

  printf("%d\n", Ordem_Inversa1(123));
  printf("%d\n", Ordem_Inversa1(9));
  printf("%d\n", Ordem_Inversa1(321));
  printf("%d\n", Ordem_Inversa1(333));
  printf("%d\n", Ordem_Inversa1(1234)); 
  printf("%d\n", Ordem_Inversa1(99999)); 
  printf("%d\n", Ordem_Inversa1(999399)); 

  Ordem_Inversa2(123, &inverso);
  printf("%d\n", inverso);
  Ordem_Inversa2(9, &inverso);
  printf("%d\n", inverso);
  Ordem_Inversa2(321, &inverso);
  printf("%d\n", inverso);
  Ordem_Inversa2(333, &inverso);
  printf("%d\n", inverso);
  Ordem_Inversa2(1234, &inverso); 
  printf("%d\n", inverso);
  Ordem_Inversa2(99999, &inverso); 
  printf("%d\n", inverso);
  Ordem_Inversa2(999399, &inverso);
  printf("%d\n", inverso); 

  return 0;
}  
