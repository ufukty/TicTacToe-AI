#pragma once

#include "TicTacToeMacros.h"

namespace TicTacToe {

struct Coordinate {
  int x, y;
};

struct Scoreboard {
  int computer, user;
};

struct Game_Data {
  __GAME_STATUS status;
  __TOKEN       turn_owner;
  __TOKEN       user_token;
  __TOKEN       computer_token;
  __BOARD_SIZE  board_size;
  __DIFFICULTY  difficulty;
  unsigned int  total_move;
  Scoreboard    scoreboard;
  Coordinate    pointer;
};

struct ab_res {
  int value, move_y, move_x;
};

struct Move {
  int     y, x;
  __TOKEN token;
};

struct Step {
  unsigned int  y, x;
  __TOKEN       token;
  __BOARD_STATE board_state;
  bool          real_move; // or just calculation
};

} // namespace TicTacToe