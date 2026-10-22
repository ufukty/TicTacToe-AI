#include "decision.h"
#include "board.h"

namespace TicTacToe {

Move Decision::decision_easy_mode(Board &board) {
  std::vector<Move> available_moves;
  for (int y = 0; y < board.meta->board_size; y++) {
    for (int x = 0; x < board.meta->board_size; x++) {
      if (board.board->Get(y, x) == TOKEN_EMPTY)
        available_moves.push_back({y, x, true});
    }
  }
  if (available_moves.size() == 0)
    return Move{-1, -1, false};

  int  rnd     = rand() % available_moves.size();
  Move ret_val = available_moves[rnd];
  return ret_val;
}

Move Decision::decision_medium_mode(Board &board) {
  Token      current_token = board.NextToken();
  Token      next_token    = current_token == TOKEN_X ? TOKEN_O : TOKEN_X;
  BoardState win_state     = board.NextToken() == TOKEN_X ? BOARD_STATE__X_WIN : BOARD_STATE__O_WIN;
  BoardState lose_state    = board.NextToken() == TOKEN_X ? BOARD_STATE__O_WIN : BOARD_STATE__X_WIN;
  BoardState board_state;
  for (int y = 0; y < board.meta->board_size; y++) { // Kazanma durumları
    for (int x = 0; x < board.meta->board_size; x++) {
      if (board.board->Get(y, x) == TOKEN_EMPTY) {
        board.Seal(y, x, false, current_token);
        board_state = board.CheckBoardState();
        board.Undo();
        if (board_state == win_state)
          return {y, x};
      }
    }
  }
  for (int y = 0; y < board.meta->board_size; y++) { // Kaybetme durumları
    for (int x = 0; x < board.meta->board_size; x++) {
      if (board.board->Get(y, x) == TOKEN_EMPTY) {
        board.Seal(y, x, false, next_token);
        board_state = board.CheckBoardState();
        board.Undo();
        if (board_state == lose_state)
          return {y, x};
      }
    }
  }
  return decision_easy_mode(board);
}

Move Decision::decision_hard_mode(Board &board) {
  if (board.NextToken() == TOKEN_X)
    alpha_beta_max(board, NEGATIVE_INFINITY, POSITIVE_INFINITY);
  else
    alpha_beta_min(board, NEGATIVE_INFINITY, POSITIVE_INFINITY);

  return Move{board.temp.predicted_move[board.meta->total_move_count + 1].y,
              board.temp.predicted_move[board.meta->total_move_count + 1].x};
}

int Decision::alpha_beta_max(Board &board, int alpha, int beta) {

  if (board.IsFinished()) // Evaluation the value of leaves according to X's condition.
    return alpha_beta_evaluate(board);

  int             value;
  std::deque<int> successors = board.SuccessorIndexList(); // successor'lerin listesi oluşturuluyor
  while (successors.size() > 0) {
    board.ToSuccessor(successors.front()); // tahta ilk ihtimal olan duruma güncelleniyor
    successors.pop_front();                // ilgili ihtimal, listeden çıkarılıyor
    // print(board);
    value = alpha_beta_min(board, alpha, beta); // hesaplama yapılıyor

    if (value > alpha) {
      alpha = value;
      board.SetPredictedSuccessor();
    }
    board.Undo(); // tahta eski haline getiriliyor.
    if (alpha >= beta || value == 10 - board.meta->total_move_count)
      return alpha;
  }

  return alpha;
}

int Decision::alpha_beta_min(Board &board, int alpha, int beta) {

  if (board.IsFinished()) // Evaluation
    return alpha_beta_evaluate(board);

  int             value;
  std::deque<int> successors = board.SuccessorIndexList(); // successor'lerin listesi oluşturuluyor
  while (successors.size() > 0) {
    board.ToSuccessor(successors.front()); // tahta ilk ihtimal olan duruma güncelleniyor
    successors.pop_front();                // ilgili ihtimal, listeden çıkarılıyor
    // print(board);
    value = alpha_beta_max(board, alpha, beta); // hesaplama yapılıyor

    if (value < beta) {
      beta = value;
      board.SetPredictedSuccessor();
    }
    board.Undo(); // tahta eski haline getiriliyor.
    if (alpha >= beta || value == board.meta->total_move_count - 10)
      return beta;
  }

  return beta;
}

int Decision::alpha_beta_evaluate(Board &board) {
  board.CheckBoardState();

  if (board.meta->board_state == BOARD_STATE__X_WIN)
    return 10 - board.meta->total_move_count;
  else if (board.meta->board_state == BOARD_STATE__O_WIN)
    return board.meta->total_move_count - 10;

  return 0;
}

} // namespace TicTacToe