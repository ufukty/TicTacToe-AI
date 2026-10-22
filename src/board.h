#pragma once

#include "macros.h"
#include "structures.h"
#include <cstdint>
#include <deque>
#include <iostream>
#include <vector>

namespace TicTacToe {

struct BoardMeta {
  std::uint8_t  total_move_count;
  std::uint8_t  maximum_move_number;
  __BOARD_SIZE  board_size;
  __BOARD_STATE board_state;
};

class Board {
public:
  struct {
    Coordinate predicted_move[26];
  } temp;

  Board(const __BOARD_SIZE size);
  ~Board(void);

  __TOKEN         next_token(void);
  __BOARD_STATE   check_board_state(void);
  __TOKEN         get(unsigned int y, unsigned int x);
  __SEAL_RESPONSE seal(unsigned int y, unsigned int x, bool real_move, __TOKEN token = TOKEN_AUTO);
  bool            undo(void);
  bool            is_game_ended(void);
  bool            set_predicted_successor(void);
  __BOARD_STATE   board_state(void);
  std::deque<unsigned int> successor_index_list(void);
  bool                     to_successor(unsigned int linear_index);

private:
  BoardMeta meta;

  __TOKEN **_board;

  std::vector<Step> _trace;
};

} // namespace TicTacToe