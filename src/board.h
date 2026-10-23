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
  BoardMeta(int size);
  bool       IsInside(Coordinates c);
  int        current_moves;
  int        max_moves;
  BoardSize  size;
  BoardState state;
};

struct BoardTemp {
  Coordinates predicted_move[26];
};

class Board {
public:
  BoardTemp  temp;
  BoardMeta *meta;
  Square    *board;

  Board(const BoardSize size);
  ~Board(void);

  BoardState      CheckBoardState(void);
  bool            IsFinished(void);
  bool            SetPredictedSuccessor(void);
  bool            ToSuccessor(int linear_index);
  bool            Undo(void);
  SealResponse    Seal(Coordinates c, bool real_move, Token token = TOKEN_AUTO);
  std::deque<int> SuccessorIndexList(void);
  Token           NextToken(void);

private:
  std::vector<Step> trace;
};

} // namespace TicTacToe