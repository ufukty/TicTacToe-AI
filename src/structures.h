#pragma once

#include "macros.h"

namespace TicTacToe {

struct Coordinates {
  int y, x;
  Coordinates() = default;
  Coordinates(int y, int x);
};

struct Scoreboard {
  int computer, user;
};

struct Game_Data {
  GameStatus  status;
  Token       turn_owner;
  Token       user_token;
  Token       computer_token;
  BoardSize   board_size;
  Difficulty  difficulty;
  int         total_move;
  Scoreboard  scoreboard;
  Coordinates pointer;
};

struct ab_res {
  int value, move_y, move_x;
};

struct Move {
  Move() = default;
  Move(Coordinates c, Token t);
  Coordinates c;
  Token       token;
};

struct Step {
  Coordinates c;
  Token       token;
  BoardState  board_state;
  bool        real_move; // or just calculation
};

} // namespace TicTacToe