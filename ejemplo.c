#include "chess.h"
#include "figures.h"
#include "gc.h"

void display(){
  int* ptr;
  memoryAlloc((void**)&ptr, sizeof(int));
  countMemoryEntries();
  unregisterPointer((void**)&ptr);
  garbageCollector();
  countMemoryEntries();
}
