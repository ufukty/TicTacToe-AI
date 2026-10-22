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
  BoardMeta::BoardMeta(int size);
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
  BoardMeta *meta;
  Square    *board;

  Board(const BoardSize size);
  ~Board(void);

  Token           NextToken(void);
  BoardState      CheckBoardState(void);
  SealResponse    Seal(int y, int x, bool real_move, Token token = TOKEN_AUTO);
  bool            Undo(void);
  bool            IsFinished(void);
  bool            SetPredictedSuccessor(void);
  std::deque<int> SuccessorIndexList(void);
  bool            ToSuccessor(int linear_index);

private:
  std::vector<Step> trace;
};

} // namespace TicTacToe