#pragma once

#include "TicTacToeBoard.h"
#include "TicTacToeDecision.h"
#include "TicTacToeMacros.h"
#include "TicTacToeStructures.h"
#include "TicTacToeUI.h"
#include "TicTacToeUserHandler.h"

namespace TicTacToe {

class TicTacToe : public UI, public Decision, public UserHandler {
public:
  TicTacToe(void);

  void enable_logs(void);
  void reset_pointer(void);
  bool start_game(void);

private:
  Game_Data game;

  void prepare_for_start();
  void print_log(std::string);
  void menu(void);
  void play(void);
};

} // namespace TicTacToe