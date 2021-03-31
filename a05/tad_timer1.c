#include "tad_timer.h"

typedef struct timer{
  time_t tempoInicial;
  time_t tempoFinal;
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
  time(&t->tempoInicial);
}

void timer_stop(Timer* t){
  time(&t->tempoFinal);
}

void timer_reset(Timer* t){
  t->tempoInicial = 0;
  t->tempoFinal = 0;
}

float timer_resultado(Timer* t){
  return t->tempoFinal - t->tempoInicial;
}