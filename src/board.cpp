#include "board.h"

namespace TicTacToe {

Board::Board(BoardSize board_size) {
  meta.board_size          = board_size;
  meta.total_move_count    = 0;
  meta.board_state         = BOARD_STATE__EMPTY;
  meta.maximum_move_number = board_size * board_size;
  _board                   = new Token *[board_size];
  for (int y = 0; y < board_size; y++) {
    _board[y] = new Token[board_size];
    for (int x = 0; x < board_size; x++)
      _board[y][x] = TOKEN_EMPTY;
  }
}
Board::~Board(void) {
  for (int y = 0; y < meta.board_size; y++)
    delete[] _board[y];
  delete[] _board;
}

Token Board::next_token(void) {
  if (meta.board_state == BOARD_STATE__EMPTY || _trace.back().token == TOKEN_O)
    return TOKEN_X;
  else
    return TOKEN_O;
}
SealResponse Board::seal(unsigned int y, unsigned int x, bool real_move, Token token) {

  if (token == TOKEN_AUTO)
    token = next_token();

  if (y < 0 || meta.board_size <= y || x < 0 || meta.board_size <= x)
    return SEAL_OUT_OF_RANGE;
  else if (_board[y][x] != TOKEN_EMPTY)
    return SEAL_ALREADY_SEALED;

  _trace.push_back(Step{y, x, token, meta.board_state, real_move});

  _board[y][x] = token;
  meta.total_move_count++;
  meta.board_state = BOARD_STATE__NOT_CALCULATED;

  return SEAL_SUCCESS;
}
bool Board::undo(void) {
  if (_trace.back().real_move == true)
    return false;
  if (_trace.size() <= 0)
    return false;
  Step last_change                     = _trace.back();
  _board[last_change.y][last_change.x] = TOKEN_EMPTY;
  meta.total_move_count--;
  meta.board_state = last_change.board_state;
  _trace.pop_back();
  return true;
}
bool Board::is_game_ended(void) {
  check_board_state();
  return (meta.board_state == BOARD_STATE__DRAW || meta.board_state == BOARD_STATE__X_WIN ||
          meta.board_state == BOARD_STATE__O_WIN);
}
std::deque<unsigned int> Board::successor_index_list(void) {
  std::deque<unsigned int> list;
  unsigned int             linear_index = 0;
  for (int y = 0; y < meta.board_size; y++)
    for (int x = 0; x < meta.board_size; x++, linear_index++)
      if (_board[y][x] == TOKEN_EMPTY)
        list.push_back(linear_index);
  return list;
}
bool Board::to_successor(unsigned int linear_index) {
  return seal((linear_index / meta.board_size), linear_index % meta.board_size, false);
}
bool Board::set_predicted_successor(void) {
  if (_trace.back().real_move == true)
    return false;
  temp.predicted_move[meta.total_move_count].y = _trace.back().y;
  temp.predicted_move[meta.total_move_count].x = _trace.back().x;
  return true;
}
BoardState Board::board_state(void) { return meta.board_state; }
BoardState Board::check_board_state(void) {

  if (meta.board_state != BOARD_STATE__NOT_CALCULATED)
    return meta.board_state;

  Token sequence_sum = TOKEN_INITIAL, winner = TOKEN_INITIAL;

  for (int y = 0; y < meta.board_size; y++) { // Yatay taramalar
    sequence_sum = _board[y][0];
    for (int x = 1; x < meta.board_size; x++)
      if (_board[y][x] != sequence_sum)
        sequence_sum = TOKEN_MIXED;
    if (sequence_sum == TOKEN_X || sequence_sum == TOKEN_O) {
      winner = sequence_sum;
      break;
    }
  }
  if (winner == TOKEN_INITIAL)
    for (int x = 0; x < meta.board_size; x++) { // Dikey taramalar
      sequence_sum = _board[0][x];
      for (int y = 1; y < meta.board_size; y++)
        if (_board[y][x] != sequence_sum)
          sequence_sum = TOKEN_MIXED;
      if (sequence_sum == TOKEN_X || sequence_sum == TOKEN_O) {
        winner = sequence_sum;
        break;
      }
    }
  // Çapraz taramalar eğim=-1
  if (winner == TOKEN_INITIAL) {
    sequence_sum = _board[0][0];
    for (int x = 1; x < meta.board_size; x++)
      if (_board[x][x] != sequence_sum)
        sequence_sum = TOKEN_MIXED;
    if (sequence_sum == TOKEN_X || sequence_sum == TOKEN_O) {
      winner = sequence_sum;
    }
  }
  // Çapraz taramalar eğim=1
  if (winner == TOKEN_INITIAL) {
    sequence_sum = _board[meta.board_size - 1][0];
    for (int x = 1; x < meta.board_size; x++)
      if (_board[meta.board_size - 1 - x][x] != sequence_sum)
        sequence_sum = TOKEN_MIXED;
    if (sequence_sum == TOKEN_X || sequence_sum == TOKEN_O) {
      winner = sequence_sum;
    }
  }

  // Karar
  if (winner == TOKEN_X)
    meta.board_state = BOARD_STATE__X_WIN;
  else if (winner == TOKEN_O)
    meta.board_state = BOARD_STATE__O_WIN;
  else if (meta.maximum_move_number == meta.total_move_count)
    meta.board_state = BOARD_STATE__DRAW;
  else
    meta.board_state = BOARD_STATE__PLAYING;

  return meta.board_state;
}
Token Board::get(unsigned int y, unsigned int x) { return _board[y][x]; }

} // namespace TicTacToe