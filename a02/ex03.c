#include <stdio.h>

char Conceito1(float nota){

  if(nota > 10.0 || nota < 0) return '-';

  if(nota >= 9.0) 
    return 'A';
  else if(nota >= 7.0) 
    return 'B';
  else if(nota >= 9.0) 
    return 'C';
  else 
    return 'D';
}

void Conceito2(float nota, char* conceito){

  if(nota > 10.0 || nota < 0){
    *conceito = '-';
    return;
  } 

  if(nota >= 9.0) 
    *conceito = 'A';
  else if(nota >= 7.0) 
    *conceito = 'B';
  else if(nota >= 9.0) 
    *conceito = 'C';
  else 
    *conceito = 'D';
}

int main(){

  char conceito;

  printf("%c\n",Conceito1(10));
  printf("%c\n",Conceito1(8.6));
  printf("%c\n",Conceito1(7.0));
  printf("%c\n",Conceito1(3.2));
  printf("%c\n",Conceito1(-10));

  Conceito2(10, &conceito);
  printf("%c\n", conceito);
  Conceito2(8.6, &conceito);
  printf("%c\n", conceito);
  Conceito2(7.0, &conceito);
  printf("%c\n", conceito);
  Conceito2(3.2, &conceito);
  printf("%c\n", conceito);
  Conceito2(-10, &conceito);
  printf("%c\n", conceito);

  return 0;
}