//#include <stdio.h>
#include <stdlib.h>
#include "chess.h"
#include "gc.h"
#include <stdio.h>

char** allocateMemory(int rows, size_t cols){
  char** newFig;
  memoryAlloc((void**)&newFig, sizeof(char*)*(rows + 1));
  for(int i = 0; i < rows; i++)
    memoryAlloc((void**)&newFig[i], sizeof(char)*(cols + 1));
  fprintf(stderr, "allocateMemory()\n");
  fprintf(stderr, "Puntero: %p\n", newFig);
  fprintf(stderr, "Dirección: %p\n", &newFig);
  return newFig;
}

void unlinkMemory(char** fig){
  countMemoryEntries();
  for(int i = 0; fig[i]; i++)
    unregisterPointer((void**)&fig[i]);
  countMemoryEntries();
  unregisterPointer((void**)&fig);
  countMemoryEntries();
  fprintf(stderr, "unlinkMemory()\n");
  fprintf(stderr, "Puntero: %p\n", fig);
  fprintf(stderr, "Dirección: %p\n", &fig);
}

char** reverse(char** fig){
  int rows = 0;
  while(fig[++rows]);
  
  int cols = 0;
  while(fig[0][++cols]);

  char** newFig = allocateMemory(rows, cols);

  fprintf(stderr, "reverse()\n");
  fprintf(stderr, "Puntero: %p\n", newFig);
  fprintf(stderr, "Dirección: %p\n", &newFig);

  for(int i = 0; fig[i]; i++){
    for(int j = 0; fig[0][j]; j++)
      newFig[i][j] = fig[i][j];
    newFig[i][cols] = 0;
  }
  newFig[rows] = 0;
  unlinkMemory(newFig);
  return newFig;
}

