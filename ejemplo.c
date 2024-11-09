#include "chess.h"
#include "figures.h"
#include "gc.h"

#define SIZE 10

void function(void** ptr){
  unregisterPointer(ptr);
}

void display(){
  int** ptr;
  memoryAlloc((void**)&ptr, sizeof(int*) * SIZE);
  for (int i=0; i<SIZE; ++i)
    memoryAlloc((void**)&ptr[i], sizeof(int) * SIZE); 
  countMemoryEntries();
  
  for (int i=0; i<SIZE; ++i)
    function((void**)&ptr[i]);
  countMemoryEntries();
  
  function((void**)&ptr);
  garbageCollector();
  countMemoryEntries();
}
