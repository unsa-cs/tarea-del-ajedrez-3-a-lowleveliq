#include "chess.h"
#include "figures.h"
#include "gc.h"

#define SIZE 10

void destruir(int* ptr){
  unregisterPointer((void**)&ptr);
}

int* crear(){
  int* ptr;
  memoryAlloc((void**)&ptr, sizeof(int));
  return ptr;
}
void display(){
  int* ptr = crear();
  countMemoryEntries();
  destruir(ptr); 
  garbageCollector();
  countMemoryEntries();
}
