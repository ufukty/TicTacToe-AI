#include "structures.h"

namespace TicTacToe {

Coordinates::Coordinates(int y, int x) : y(y), x(x) { ; }

Move::Move(Coordinates c, Token t) : c(c), token(t) { ; }

} // namespace TicTacToe
