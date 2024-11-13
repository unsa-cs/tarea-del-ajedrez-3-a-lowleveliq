#include "chess.h"
#include "figures.h"
#include "gc.h"

void display(){
  char** blackSquare = reverse(whiteSquare);
  char** blakcKnight = reverse(knight);
  char** blakcQueen = reverse(queen);
  interpreter(blackSquare);
  garbageCollector();
}
