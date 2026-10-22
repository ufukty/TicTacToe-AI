#pragma once

#include "macros.h"

namespace TicTacToe {

class Square {
private:
  int     size;
  Token **data;

public:
  Square(int size);
  ~Square(void);
  Token Get(int y, int x);
  void  Set(int y, int x, Token value);
};

}; // namespace TicTacToe