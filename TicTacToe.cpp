#include <string>
#include <conio.h>
#include "TicTacToe.h"

namespace TicTacToe {

	TicTacToe::TicTacToe(void)
	{
		game.overall_score.computer = game.overall_score.user = 0;
		game.status = GAME_INITIALIZED;
	}

	void TicTacToe::prepare_for_start() {
		game.turn_owner = TOKEN_X; // X always goes first.
		game.total_move = 0;
		UI::prepare_for_start();
	}

	void TicTacToe::enable_logs(void)
	{

	}

	void TicTacToe::print_log(std::string log)
	{

	}

	void TicTacToe::menu(void) {
		__USER_ACTION user_action;

		reset_pointer();
		game.status = GAME_MENU_SCREEN_1;

		while (true) {
			render_menu_screen(game);
			user_action = input_on_menu_screen(game);

			if (user_action == USER__NEXT_MENU_PAGE) {
				game.status++;
				reset_pointer();
			}
			else if (user_action == USER__PREVIOUS_MENU_PAGE) {
				game.status--;
				reset_pointer();
			}
			else if (user_action == USER__ALL_SETTINGS_COMPLETED) {
				game.status = GAME_MENU_COMPLETED;
				reset_pointer();
				break;
			}
		}
	}

	void TicTacToe::play(void) {
		__USER_ACTION user_action;

		game.status = GAME_PLAYING;
		reset_pointer();

		Board board(game.board_size);

		while (board.is_game_ended() == false) {

			render_game_screen(board, game);

			if (board.next_token() == game.computer_token) { // Bilgisayarın sırası
				Move move;
				if (game.difficulty == EASY)
					move = decision_easy_mode(board);
				else if (game.difficulty == MEDIUM)
					move = decision_medium_mode(board);
				else
					move = decision_hard_mode(board);
				board.seal(move.y, move.x, true);
				game.pointer.y = move.y;
				game.pointer.x = move.x;
			}
			else { // Kullanıcının sırası

				user_action = input_on_game_screen(game);

				if (user_action == USER__MOVE_REQUEST_OUT_OF_RANGE_TOP)
					display_message("Daha fazla yukari gidilemez.");
				else if (user_action == USER__MOVE_REQUEST_OUT_OF_RANGE_LEFT)
					display_message("Daha fazla sola gidilemez.");
				else if (user_action == USER__MOVE_REQUEST_OUT_OF_RANGE_RIGHT)
					display_message("Daha fazla saga gidilemez.");
				else if (user_action == USER__MOVE_REQUEST_OUT_OF_RANGE_BOTTOM)
					display_message("Daha fazla asagi gidilemez.");
				else if (user_action == USER__HINT) {
					Move move = decision_hard_mode(board);
					game.pointer.y = move.y;
					game.pointer.x = move.x;
					display_message("En iyi yer burasi.");
				}

				if (user_action != USER__FILL_REQUEST) continue;

				__SEAL_RESPONSE response = board.seal(game.pointer.y, game.pointer.x, true);

				if (response == SEAL_SUCCESS) {
					;
				}
				else if (response == SEAL_ALREADY_SEALED) {
					display_message("Burasi zaten dolu, baska bir alani secin.");
				}
			}

			board.check_board_state();
		}

		int end;
		if (board.board_state() == BOARD_STATE__X_WIN) {
			if (game.user_token == TOKEN_X) end = 1;
			else end = 2;
		}
		else if (board.board_state() == BOARD_STATE__O_WIN) {
			if (game.user_token == TOKEN_X) end = 2;
			else end = 1;
		}
		else if (board.board_state() == BOARD_STATE__DRAW)
			end = 3;
		
		if (end == 1) {
			display_message("Kazandiniz");
			game.overall_score.user++;
		}
		else if (end == 2) {
				display_message("Kaybettiniz");
				game.overall_score.computer++;
		}
		else if (end == 3)
			display_message("Berabere");

		render_game_screen(board, game);

		game.status = GAME_ABOUT_TO_RESTART;
		_getch();
	}

	void TicTacToe::reset_pointer(void) {
		if (game.status == GAME_PLAYING)
			game.pointer.x = game.pointer.y = (game.board_size - 1) / 2;
		else
			game.pointer.x = game.pointer.y = 0;
	}

	bool TicTacToe::start_game(void)
	{
		if (game.status != GAME_INITIALIZED)
			return false;

		game.status = GAME_WELCOME_SCREEN;
		render_opening_screen();

		while (true) { // Play again

			menu();

			prepare_for_start();

			play();

		}	

		return true;
	}

}