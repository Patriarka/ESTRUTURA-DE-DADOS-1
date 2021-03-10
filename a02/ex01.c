#include <stdio.h>

float Potencia1(float base, int expoente){
  if(expoente == 0) return 1;
  if(expoente >= 1) return base *= Potencia1(base, expoente-1);
  else return Potencia1(1/base, expoente*(-1));
}

void Potencia2(int base, int expoente, float* res){
  
  int qtdeIteracoes = (expoente >= 0 ? expoente : expoente*(-1));

  *res = 1;
  for(int i = 0; i < qtdeIteracoes; i++)
    *res *= base;

  *res = (expoente >= 0 ? *res : 1/(*res));
}

int main(){

  float res;

  printf("10^2: %.2f\n", Potencia1(10,2));
  printf("10^0: %.2f\n", Potencia1(10,0));
  printf("(-10)^2: %.2f\n", Potencia1(-10,2));
  printf("10^(-5): %.5f\n", Potencia1(10,-5));
  printf("5^(-4): %.4f\n", Potencia1(5,-4));

  Potencia2(10,2,&res);
  printf("10^2: %.2f\n", res);
  Potencia2(10,0,&res);
  printf("10^0: %.2f\n", res);
  Potencia2(-10,2,&res);
  printf("(-10)^2: %.2f\n", res);
  Potencia2(10,-5,&res);
  printf("10^(-5): %.5f\n", res);
  Potencia2(5,-4,&res);
  printf("5^(-4): %.4f\n", res);

  return 0;
}