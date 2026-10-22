#include "square.h"
#include "macros.h"
#include "structures.h"

namespace TicTacToe {

Square::Square(int size) : size(size) {
  data = new int *[size];
  for (int y = 0; y < size; y++) {
    data[y] = new int[size];
    for (int x = 0; x < size; x++)
      data[y][x] = 0;
  }
};

Square::~Square(void) {
  for (int y = 0; y < this->size; y++)
    delete[] this->data[y];
  delete[] this->data;
}

Token Square::Get(int y, int x) { return this->data[y][x]; }
Token Square::Get(Coordinates c) { return Get(c.y, c.x); }

void Square::Set(int y, int x, Token value) { this->data[y][x] = value; }
void Square::Set(Coordinates c, Token value) { Set(c.y, c.x, value); }

}; // namespace TicTacToe