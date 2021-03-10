#include <stdio.h>

int Contar_String(char* str){
  int i = 0;
  while(str[i] != '\0')
    i++;
  return i;
}

void Inverter_String(char* str){
  
  int tamStr = Contar_String(str);
  char auxiliar[tamStr];
  auxiliar[tamStr] = '\0';

  int i, j;
  for(i = tamStr-1, j = 0; i >= 0; i--)
    auxiliar[i] = str[j++];
  for(i = 0; i < tamStr; i++)
    str[i] = auxiliar[i];
}

int main(){

  char str[] = {'U','T','F','P','R','\0'};

  Inverter_String(str);

  printf("%s\n", str);

  return 0;
}