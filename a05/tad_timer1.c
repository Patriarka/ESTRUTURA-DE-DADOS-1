#include "tad_timer.h"

Timer* timer_criar(){
  Timer* novo_timer = (Timer*) malloc(sizeof(Timer));
  return novo_timer;
}

void timer_desalocar(Timer** t){
  free(*t);
  *t = NULL;
}

void timer_start(Timer* t){
  
  time_t auxiliarTempoInicial;

  time(&auxiliarTempoInicial);
  t->tempoInicial = auxiliarTempoInicial;  
}

void timer_stop(Timer* t){

  time_t auxiliarTempoFinal;

  time(&auxiliarTempoFinal);
  t->tempoFinal = auxiliarTempoFinal;
}

void timer_reset(Timer* t){
  t->tempoInicial = 0;
  t->tempoFinal = 0;
}

float timer_resultado(Timer* t){
  return t->tempoFinal - t->tempoInicial;
}