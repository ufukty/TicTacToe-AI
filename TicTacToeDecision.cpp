#include "TicTacToeDecision.h"
#include "TicTacToeBoard.h"

#include <Windows.h>

namespace TicTacToe {

	Decision::Decision(void){
		;
	}

	Move Decision::decision_easy_mode(Board &board)
	{
		std::vector<Move> available_moves;
		for (int y = 0; y < board.meta().board_size; y++) {
			for (int x = 0; x < board.meta().board_size; x++) {
				if (board.get(y, x) == TOKEN_EMPTY)
					available_moves.push_back({ y, x, true });
			}
		}
		if (available_moves.size() == 0) return	Move{ -1, -1, false };

		unsigned int rnd = rand() % available_moves.size();
		Move ret_val = available_moves[rnd];
		return ret_val;
	}

	Move Decision::decision_medium_mode(Board &board)
	{
		__TOKEN current_token = board.next_token();
		__TOKEN next_token = current_token == TOKEN_X ? TOKEN_O : TOKEN_X;
		__BOARD_STATE win_state = board.next_token() == TOKEN_X ? BOARD_STATE__X_WIN : BOARD_STATE__O_WIN;
		__BOARD_STATE lose_state = board.next_token() == TOKEN_X ? BOARD_STATE__O_WIN : BOARD_STATE__X_WIN;
		__BOARD_STATE board_state;
		for (int y = 0; y < board.meta().board_size; y++) { // Kazanma durumları
			for (int x = 0; x < board.meta().board_size; x++) {
				if (board.get(y, x) == TOKEN_EMPTY) {
					board.seal(y, x, false, current_token);
					board_state = board.check_board_state();
					board.undo();
					if (board_state == win_state) return{ y, x };
				}
			}
		}
		for (int y = 0; y < board.meta().board_size; y++) { // Kaybetme durumları
			for (int x = 0; x < board.meta().board_size; x++) {
				if (board.get(y, x) == TOKEN_EMPTY) {
					board.seal(y, x, false, next_token);
					board_state = board.check_board_state();
					board.undo();
					if (board_state == lose_state) return{ y, x };
				}
			}
		}
		return decision_easy_mode(board);
	}

	Move Decision::decision_hard_mode(Board &board)
	{
		if (board.next_token() == TOKEN_X)
			alpha_beta_max(board, NEGATIVE_INFINITY, POSITIVE_INFINITY);
		else
			alpha_beta_min(board, NEGATIVE_INFINITY, POSITIVE_INFINITY);

		return Move{
			board.temp.predicted_move[board.meta().total_move_count + 1].y,
			board.temp.predicted_move[board.meta().total_move_count + 1].x
		};
	}

	int Decision::alpha_beta_max(Board &board, int alpha, int beta) {

		if (board.is_game_ended()) // Evaluation the value of leaves according to X's condition.
			return alpha_beta_evaluate(board);

		int value;
		std::deque<unsigned int> successors = board.successor_index_list(); // successor'lerin listesi oluşturuluyor
		while (successors.size() > 0) {
			board.to_successor(successors.front()); // tahta ilk ihtimal olan duruma güncelleniyor
			successors.pop_front(); // ilgili ihtimal, listeden çıkarılıyor
			//print(board);
			value = alpha_beta_min(board, alpha, beta); // hesaplama yapılıyor

			if (value > alpha) {
				alpha = value;
				board.set_predicted_successor();
			}
			board.undo(); // tahta eski haline getiriliyor.
			if (alpha >= beta || value == 10 - board.meta().total_move_count)
				return alpha;
		}

		return alpha;
	}
	int Decision::alpha_beta_min(Board &board, int alpha, int beta) {

		if (board.is_game_ended()) // Evaluation
			return alpha_beta_evaluate(board);

		int value;
		std::deque<unsigned int> successors = board.successor_index_list(); // successor'lerin listesi oluşturuluyor
		while (successors.size() > 0) {
			board.to_successor(successors.front()); // tahta ilk ihtimal olan duruma güncelleniyor
			successors.pop_front(); // ilgili ihtimal, listeden çıkarılıyor
			//print(board);
			value = alpha_beta_max(board, alpha, beta); // hesaplama yapılıyor

			if (value < beta) {
				beta = value;
				board.set_predicted_successor();
			}
			board.undo(); // tahta eski haline getiriliyor.
			if (alpha >= beta || value == board.meta().total_move_count - 10)
				return beta;
		}

		return beta;
	}

	int Decision::alpha_beta_evaluate(Board &board)
	{
		board.check_board_state();
		
		if (board.meta().board_state == BOARD_STATE__X_WIN)
			return 10 - board.meta().total_move_count;
		else if (board.meta().board_state == BOARD_STATE__O_WIN)
			return board.meta().total_move_count - 10;
		
		return 0;
	}

}