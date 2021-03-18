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
  char str2[] = {'C','u','r','r','y','\0'};

  Contar_String(str, &tamStr);
  printf("%d\n", tamStr);

  Contar_String(str2, &tamStr);
  printf("%d\n", tamStr);

  return 0;
}