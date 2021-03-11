#include <stdio.h>

float Potencia1(int base, int expoente){
  int qtdeIteracoes = (expoente >= 0 ? expoente : expoente*(-1));

  int res = 1;
  for(int i = 0; i < qtdeIteracoes; i++)
    res *= base;

  return (expoente >= 0 ? res : (float)1/res);
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
