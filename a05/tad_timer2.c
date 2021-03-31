#include "tad_timer.h"

typedef struct timer{
  double tempoInicial;
  double tempoFinal;
} Timer;

Timer* timer_criar(){
  Timer* novo_timer = (Timer*) malloc(sizeof(Timer));
  return novo_timer;
}

void timer_desalocar(Timer** t){
  free(*t);
  *t = NULL;
}

void timer_start(Timer* t){
  t->tempoInicial = clock();
}

void timer_stop(Timer* t){
  t->tempoFinal = clock();
}

void timer_reset(Timer* t){
  t->tempoInicial = 0;
  t->tempoFinal = 0;
}

float timer_resultado(Timer* t){
  return (float)(t->tempoFinal - t->tempoInicial)/CLOCKS_PER_SEC;
}