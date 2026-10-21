#pragma once

#include "TicTacToeBoard.h"
#include "TicTacToeMacros.h"
#include "TicTacToeStructures.h"

namespace TicTacToe {

class Decision {

protected:
  Decision(void);

  Move decision_easy_mode(Board &board);
  Move decision_medium_mode(Board &board);
  Move decision_hard_mode(Board &board);

private:
  int alpha_beta_max(Board &, int, int);
  int alpha_beta_min(Board &, int, int);
  int alpha_beta_evaluate(Board &);
};

} // namespace TicTacToe