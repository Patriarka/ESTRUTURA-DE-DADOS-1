#include <stdio.h>

int Contar_String(char* str){
  int i = 0;
  while(str[i] != '\0')
    i++;
  return i;
}

void Copia_String(char* str1, char* str2){
  int tam = Contar_String(str1);
  for(int i = 0; i <= tam; i++)
    str2[i] = str1[i];
}

int main(){
  
  char str1[] = {'B','u','l','l','s','\0'};
  char str2[] = {'W','a','r','r','i','o','r','s','\0'};

  Copia_String(str1, str2);
  printf("%s\n", str2);

  return 0;
}
