#pragma once

#include "macros.h"
#include "structures.h"

namespace TicTacToe {
class UserHandler {
protected:
  UserAction input_on_menu_screen(Game_Data &);
  UserAction input_on_game_screen(Game_Data &);
};

} // namespace TicTacToe