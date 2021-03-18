#include <stdio.h>

int Contar_String(char* str){
  
  int i = 0;
  while(str[i] != '\0')
    i++;
  return i;
}

void Copia_String(char* str1, char* str2){

  int tam = Contar_String(str2);
  int i;
  for(i = 0; i < tam; i++)
    str1[i] = str2[i];
  str1[i] = '\0';
}

int main(){

  char str1[10];
  char str2[] = {'B','u','l','l','s','\0'};

  Copia_String(str1, str2);
  printf("%s\n", str1);

  Copia_String(str1, "Lakers");
  printf("%s\n", str1);

  Copia_String(str1, "Celtics");
  printf("%s\n", str1);

  Copia_String(str1, "Wizards");
  printf("%s\n", str1);

  return 0;
}
