#include "chess.h"
#include "figures.h"
#include "gc.h"
#include <stdio.h>

void display(){
  char** blackSquare = reverse(whiteSquare);
  fprintf(stderr, "main()\n");
  fprintf(stderr, "Puntero: %p\n", blackSquare);
  fprintf(stderr, "Dirección: %p\n", &blackSquare);
  interpreter(blackSquare);
  garbageCollector();
}
