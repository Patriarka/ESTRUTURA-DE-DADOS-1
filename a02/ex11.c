#include <stdio.h>

int Contar_String(char* str){
  int i = 0;
  while(str[i] != '\0')
    i++;
  return i;
}

void Conta_Vogais(char* str, int* cont){
  
  int tam = Contar_String(str);
  
  *cont = 0;
  for(int i = 0; i < tam; i++){
    if(str[i] == 'a' || str[i] == 'e' 
      || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        (*cont)++;
  }
}

int main(){

  int cont;
  char str[] = {'C','h','i','c','a','g','o','\0'};

  Conta_Vogais(str, &cont);

  printf("%d\n", cont);

  return 0;
}