#include <stdio.h>
#include <ctype.h>

int Contar_String(char* str){
  int i = 0;
  while(str[i] != '\0')
    i++;
  return i;
}

void Converter_Minusculo(char* str){

  int tam = Contar_String(str);
  for(int i = 0; i < tam; i++)
    str[i] = tolower(str[i]);
}

void Conta_Vogais(char* str, int* cont){
  
  int tam = Contar_String(str);
  Converter_Minusculo(str);
  
  *cont = 0;
  for(int i = 0; i < tam; i++){
    if(str[i] == 'a' || str[i] == 'e' 
      || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        (*cont)++;
  }
}

int main(){

  int cont;
  char str1[] = {'C','h','i','c','a','g','o','\0'};
  char str2[] = {'w','w','w','\0'};
  char str3[] = {'I','E','E','E','\0'};

  Conta_Vogais(str1, &cont);
  printf("%d\n", cont);

  Conta_Vogais(str2, &cont);
  printf("%d\n", cont);

  Conta_Vogais(str3, &cont);
  printf("%d\n", cont);

  return 0;
}