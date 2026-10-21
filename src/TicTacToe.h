#pragma once

#include "board.h"
#include "decision.h"
#include "macros.h"
#include "structures.h"
#include "ui.h"
#include "userHandler.h"

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