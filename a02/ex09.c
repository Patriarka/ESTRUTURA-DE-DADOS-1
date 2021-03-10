#include <stdio.h>

void Contar_String(char* str, int* tamStr){
  *tamStr = 0;
  while(str[*tamStr] != '\0'){
    (*tamStr)++;
  }
}

int main(){

  int tamStr;
  char str[] = {'J','o','r','d','a','n','\0'};

  Contar_String(str, &tamStr);

  printf("%d\n", tamStr);

  return 0;
}