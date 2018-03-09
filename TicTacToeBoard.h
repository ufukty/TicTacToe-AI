#pragma once

#include <iostream>
#include <deque>
#include <vector>

#include "TicTacToeMacros.h"
#include "TicTacToeStructures.h"

namespace TicTacToe {

	class Board {
	public:
		struct Meta {
			unsigned __int8		total_move_count;
			unsigned __int8		maximum_move_number;
			__BOARD_SIZE		board_size;
			__BOARD_STATE		board_state;
		};
		
		struct {
			struct {
				unsigned __int8 y, x;
			} predicted_move[26];
		} temp;

		Board(const __BOARD_SIZE size);
		~Board(void);

		__TOKEN						next_token			(void);
		__BOARD_STATE				check_board_state	(void);
		__TOKEN						get					(unsigned int y, unsigned int x);
		__SEAL_RESPONSE				seal(unsigned int y, unsigned int x, bool real_move, __TOKEN token = TOKEN_AUTO);
		bool						undo				(void);
		const Meta &				meta				(void);
		const std::vector<Step> &	trace				(void);
		bool						is_game_ended		(void);
		bool						set_predicted_successor(void);
		__BOARD_STATE				board_state			(void);
		std::deque<unsigned int>	successor_index_list(void);
		bool						to_successor		(unsigned int linear_index);

	private:
								
		Meta					_meta;
								
		__TOKEN					**_board;
				
		std::vector<Step>		_trace;
	};

}