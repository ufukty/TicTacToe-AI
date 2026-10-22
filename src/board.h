#pragma once

#include "macros.h"
#include "square.h"
#include "structures.h"
#include <cstdint>
#include <deque>
#include <iostream>
#include <vector>

namespace TicTacToe {

struct BoardMeta {
  int        total_move_count;
  int        maximum_move_number;
  BoardSize  board_size;
  BoardState board_state;
};

class Board {
public:
  struct {
    Coordinate predicted_move[26];
  } temp;
  BoardMeta meta;
  Square   *board;

  Board(const BoardSize size);
  ~Board(void);

  Token           next_token(void);
  BoardState      check_board_state(void);
  Token           get(int y, int x);
  SealResponse    seal(int y, int x, bool real_move, Token token = TOKEN_AUTO);
  bool            undo(void);
  bool            is_game_ended(void);
  bool            set_predicted_successor(void);
  BoardState      board_state(void);
  std::deque<int> successor_index_list(void);
  bool            to_successor(int linear_index);

private:
  std::vector<Step> _trace;
};

} // namespace TicTacToe