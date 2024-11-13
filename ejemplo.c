#include "chess.h"
#include "figures.h"
#include "gc.h"
#include <stdio.h>

void display(){ 
  int *a;
  memoryAlloc((void **)&a, sizeof(int));
  int *b;
  registerPointerToMemory((void **)&b, (void *)a);
  *b = 3;
  printf("a = %d\n", *a); // debe imprimir a = 3;
  unregisterPointer((void **)&a);
  unregisterPointer((void **)&b);
  garbageCollector();
}
