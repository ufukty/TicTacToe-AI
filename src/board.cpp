#include "board.h"
#include "macros.h"
#include "square.h"

namespace TicTacToe {

BoardMeta::BoardMeta(int size) {
  board_size          = size;
  total_move_count    = 0;
  board_state         = BOARD_STATE__EMPTY;
  maximum_move_number = size * size;
}

bool isInside(int value, int low, int high) { return low <= value && value <= high; }

bool BoardMeta::IsInside(Coordinates c) {
  return isInside(c.y, 0, board_size) && isInside(c.x, 0, board_size);
}

Board::Board(const BoardSize s) {
  meta  = new BoardMeta(s);
  board = new Square(s);
}

Board::~Board(void) { board->~Square(); }

Token Board::NextToken(void) {
  return meta->board_state == BOARD_STATE__EMPTY || trace.back().token == TOKEN_O ? TOKEN_X
                                                                                  : TOKEN_O;
}

SealResponse Board::Seal(Coordinates c, bool real_move, Token t) {
  if (!meta->IsInside(c)) {
    return SEAL_OUT_OF_RANGE;
  }
  if (board->Get(c) != TOKEN_EMPTY) {
    return SEAL_ALREADY_SEALED;
  }
  if (t == TOKEN_AUTO) {
    t = NextToken();
  }
  trace.push_back(Step{c, t, meta->board_state, real_move});

  board->Set(c, t);
  meta->total_move_count++;
  meta->board_state = BOARD_STATE__NOT_CALCULATED;

  return SEAL_SUCCESS;
}

bool Board::Undo(void) {
  if (trace.back().real_move == true)
    return false;
  if (trace.size() <= 0)
    return false;
  Step last_change = trace.back();
  board->Set(last_change.c, TOKEN_EMPTY);
  meta->total_move_count--;
  meta->board_state = last_change.board_state;
  trace.pop_back();
  return true;
}

bool Board::IsFinished(void) {
  CheckBoardState();
  return (meta->board_state == BOARD_STATE__DRAW || meta->board_state == BOARD_STATE__X_WIN ||
          meta->board_state == BOARD_STATE__O_WIN);
}

std::deque<int> Board::SuccessorIndexList(void) {
  std::deque<int> list;
  int             linear_index = 0;
  for (int y = 0; y < meta->board_size; y++)
    for (int x = 0; x < meta->board_size; x++, linear_index++)
      if (board->Get(y, x) == TOKEN_EMPTY)
        list.push_back(linear_index);
  return list;
}

bool Board::ToSuccessor(int linear_index) {
  Coordinates c = Coordinates{linear_index / meta->board_size, linear_index % meta->board_size};
  return Seal(c, false);
}

bool Board::SetPredictedSuccessor(void) {
  if (trace.back().real_move == true)
    return false;
  temp.predicted_move[meta->total_move_count] = trace.back().c;
  return true;
}

BoardState Board::CheckBoardState(void) {

  if (meta->board_state != BOARD_STATE__NOT_CALCULATED)
    return meta->board_state;

  Token sequence_sum = TOKEN_INITIAL, winner = TOKEN_INITIAL;

  for (int y = 0; y < meta->board_size; y++) { // Yatay taramalar
    sequence_sum = board->Get(y, 0);
    for (int x = 1; x < meta->board_size; x++)
      if (board->Get(y, x) != sequence_sum)
        sequence_sum = TOKEN_MIXED;
    if (sequence_sum == TOKEN_X || sequence_sum == TOKEN_O) {
      winner = sequence_sum;
      break;
    }
  }
  if (winner == TOKEN_INITIAL)
    for (int x = 0; x < meta->board_size; x++) { // Dikey taramalar
      sequence_sum = board->Get(0, x);
      for (int y = 1; y < meta->board_size; y++)
        if (board->Get(y, x) != sequence_sum)
          sequence_sum = TOKEN_MIXED;
      if (sequence_sum == TOKEN_X || sequence_sum == TOKEN_O) {
        winner = sequence_sum;
        break;
      }
    }
  // Çapraz taramalar eğim=-1
  if (winner == TOKEN_INITIAL) {
    sequence_sum = board->Get(0, 0);
    for (int x = 1; x < meta->board_size; x++)
      if (board->Get(x, x) != sequence_sum)
        sequence_sum = TOKEN_MIXED;
    if (sequence_sum == TOKEN_X || sequence_sum == TOKEN_O) {
      winner = sequence_sum;
    }
  }
  // Çapraz taramalar eğim=1
  if (winner == TOKEN_INITIAL) {
    sequence_sum = board->Get(meta->board_size - 1, 0);
    for (int x = 1; x < meta->board_size; x++)
      if (board->Get(meta->board_size - 1 - x, x) != sequence_sum)
        sequence_sum = TOKEN_MIXED;
    if (sequence_sum == TOKEN_X || sequence_sum == TOKEN_O) {
      winner = sequence_sum;
    }
  }

  // Karar
  if (winner == TOKEN_X)
    meta->board_state = BOARD_STATE__X_WIN;
  else if (winner == TOKEN_O)
    meta->board_state = BOARD_STATE__O_WIN;
  else if (meta->maximum_move_number == meta->total_move_count)
    meta->board_state = BOARD_STATE__DRAW;
  else
    meta->board_state = BOARD_STATE__PLAYING;

  return meta->board_state;
}

} // namespace TicTacToe