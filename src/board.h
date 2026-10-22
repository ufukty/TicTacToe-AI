#pragma once

#include "macros.h"
#include "structures.h"
#include <cstdint>
#include <deque>
#include <iostream>
#include <vector>

namespace TicTacToe {

struct BoardMeta {
  std::uint8_t total_move_count;
  std::uint8_t maximum_move_number;
  BoardSize    board_size;
  BoardState   board_state;
};

class Board {
public:
  struct {
    Coordinate predicted_move[26];
  } temp;
  BoardMeta meta;
  Token   **_board;

  Board(const BoardSize size);
  ~Board(void);

  Token        next_token(void);
  BoardState   check_board_state(void);
  Token        get(unsigned int y, unsigned int x);
  SealResponse seal(unsigned int y, unsigned int x, bool real_move, Token token = TOKEN_AUTO);
  bool         undo(void);
  bool         is_game_ended(void);
  bool         set_predicted_successor(void);
  BoardState   board_state(void);
  std::deque<unsigned int> successor_index_list(void);
  bool                     to_successor(unsigned int linear_index);

private:
  std::vector<Step> _trace;
};

} // namespace TicTacToe