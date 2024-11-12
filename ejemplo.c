#include "chess.h"
#include "figures.h"
#include "gc.h"
#include <stdio.h>

void display(){
  char** blackSquare = reverse(whiteSquare);
  interpreter(blackSquare);
  garbageCollector();
}
