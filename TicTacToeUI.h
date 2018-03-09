#pragma once

#include "TicTacToeMacros.h"
#include "TicTacToeStructures.h"
#include "TicTacToeBoard.h"

namespace TicTacToe {

	class UI {
	private:

		template<typename T>void set_scene(T &callback, int iteration, int interval);
		void repeat_print(int t, char c);
		void repeat_str(std::string &, int t, char c);
		void header(Game_Data &);
		void print_board(Board &, Game_Data &);

		std::string message;
		bool message_flag;

	protected:

		void centered(std::string &);

		void render_opening_screen(void);
		void render_menu_screen(Game_Data &);
		void render_game_screen(Board &, Game_Data &);

		void display_message(const char[]);

	public:

		UI(void);

		void prepare_for_start(void);

	};

}