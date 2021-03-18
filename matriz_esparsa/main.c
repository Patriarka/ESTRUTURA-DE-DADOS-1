#include <stdio.h>
#include "matriz_esparsa.h"

int main(){

  Matriz* m = matriz_criar(3,3);

  matriz_acessar(m, 0, 0);

  matriz_desalocar(m);

  return 0;
}