#include <stdio.h>

int Contar_String(char* str){
  int i = 0;
  while(str[i] != '\0')
    i++;
  return i;
}

char* Copia_Str(char* str1, char* str2){

  int tam = Contar_String(str1);

  int i;
  for(i = 0; i < tam; i++)
    str2[i] = str1[i];
  str2[i] = '\0';

  return 0;
}

int main(){

  char str1[] = {'B','U','L','L','S','\0'};
  char str2[] = {'W','A','R','R','I','O','R','S','\0'};

  printf("%s\n", str2);
  Copia_Str(str1, str2);
  printf("%s\n", str2);

  return 0;
}