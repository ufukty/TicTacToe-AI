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

#include "TicTacToeBoard.h"
#include "TicTacToeUI.h"
#include "TicTacToeDecision.h"
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

}