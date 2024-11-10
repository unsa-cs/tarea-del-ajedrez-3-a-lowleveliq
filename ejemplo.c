#include "chess.h"
#include "figures.h"
#include "gc.h"
#include <stdio.h>

#define SIZE 10

void destruir(int* ptr){ 
  fprintf(stderr, "destruir()\n");
  fprintf(stderr, "Puntero: %p\n", ptr);
  fprintf(stderr, "Dirección: %p\n", &ptr);
  unregisterPointer((void**)&ptr);
}

int* crear(){
  int* ptr;
  memoryAlloc((void**)&ptr, sizeof(int));
  fprintf(stderr, "crear()\n");
  fprintf(stderr, "Puntero: %p\n", ptr);
  fprintf(stderr, "Dirección: %p\n", &ptr);
  return ptr;
}

void display(){
  char** blackSquare = reverse(whiteSquare);
  fprintf(stderr, "main()\n");
  fprintf(stderr, "Puntero: %p\n", blackSquare);
  fprintf(stderr, "Dirección: %p\n", &blackSquare);
  interpreter(blackSquare);
  garbageCollector();
}
