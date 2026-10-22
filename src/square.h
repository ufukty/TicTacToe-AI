#pragma once

#include "macros.h"
#include "structures.h"

namespace TicTacToe {

class Square {
private:
  int     size;
  Token **data;

public:
  Square(int size);
  ~Square(void);
  Token Get(Coordinates c);
  Token Get(int y, int x);
  void  Set(Coordinates c, Token value);
  void  Set(int y, int x, Token value);
};

}; // namespace TicTacToe