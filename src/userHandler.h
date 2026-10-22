#pragma once

#include "macros.h"
#include "structures.h"

namespace TicTacToe {
class UserHandler {
public:
  UserHandler();

protected:
  __USER_ACTION input_on_menu_screen(Game_Data &);
  __USER_ACTION input_on_game_screen(Game_Data &);
};

} // namespace TicTacToe