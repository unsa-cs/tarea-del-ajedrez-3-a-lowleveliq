#include "chess.h"
#include "figures.h"
#include "gc.h"

#define SIZE 10

void display(){
  int** ptr;
  memoryAlloc((void**)&ptr, sizeof(int*) * SIZE);
  for (int i=0; i<SIZE; ++i)
    memoryAlloc((void**)&ptr[i], sizeof(int) * SIZE); 
  countMemoryEntries();
  
  for (int i=0; i<SIZE; ++i)
    unregisterPointer((void**)&ptr[i]);
  countMemoryEntries();
  
  unregisterPointer((void**)&ptr);
  garbageCollector();
  countMemoryEntries();
}
