#pragma once

#include "macros.h"

namespace TicTacToe {

struct Coordinate {
  int x, y;
};

struct Scoreboard {
  int computer, user;
};

struct Game_Data {
  GameStatus   status;
  Token        turn_owner;
  Token        user_token;
  Token        computer_token;
  BoardSize    board_size;
  Difficulty   difficulty;
  unsigned int total_move;
  Scoreboard   scoreboard;
  Coordinate   pointer;
};

struct ab_res {
  int value, move_y, move_x;
};

struct Move {
  int   y, x;
  Token token;
};

struct Step {
  unsigned int y, x;
  Token        token;
  BoardState   board_state;
  bool         real_move; // or just calculation
};

} // namespace TicTacToe