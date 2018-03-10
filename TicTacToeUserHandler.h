/*
TicTacToe-v2.1-EN

Ufuk Tan
github.com/ufukty

Gameplay available at https://youtu.be/X9GnQvv_bo4

GNU General Public License v3.0
*/

#pragma once

#include "TicTacToeMacros.h"
#include "TicTacToeStructures.h"

namespace TicTacToe {

	class UserHandler {
	public:
		UserHandler();

	protected:
		__USER_ACTION input_on_menu_screen(Game_Data &);
		__USER_ACTION input_on_game_screen(Game_Data &);
	};

}