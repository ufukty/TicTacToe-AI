#pragma once

#include "TicTacToeMacros.h"

namespace TicTacToe {

	struct Game_Data {
		__GAME_STATUS		status;
		__TOKEN			turn_owner;
		__TOKEN			user_token;
		__TOKEN			computer_token;
		__BOARD_SIZE	board_size;
		__DIFFICULTY	difficulty;
		unsigned int	total_move;
		struct { int computer, user; } overall_score;
		struct { int x, y; } pointer;
	};

	struct ab_res {
		int value, move_y, move_x;
	};

	struct Move {
		int y, x;
		__TOKEN token;
	};

	struct Step {
		unsigned int		y, x;
		__TOKEN				token;
		__BOARD_STATE		board_state;
		bool				real_move; // or just calculation
	};

}