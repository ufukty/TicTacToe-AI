/*
TicTacToe-v2.1-EN

Ufuk Tan
github.com/ufukty

Gameplay available at https://youtu.be/X9GnQvv_bo4

GNU General Public License v3.0
*/

#include <conio.h>
#include <iostream>

#include "TicTacToeUserHandler.h"

namespace TicTacToe {


	UserHandler::UserHandler(void) {

	}

	__USER_ACTION UserHandler::input_on_menu_screen(Game_Data &game) {

		std::cout << " ";
		char input_character = _getch();

		switch (game.status)
		{
		case GAME_MENU_SCREEN_1:
		{
			switch (input_character)
			{
			case ' ':
			{
				if (game.pointer.y == 0)
					game.board_size = BOARD_SIZE_3x3;
				else if (game.pointer.y == 1)
					game.board_size = BOARD_SIZE_4x4;
				else
					game.board_size = BOARD_SIZE_5x5;
				return USER__NEXT_MENU_PAGE;
			}
			case 'W':
			case 'w':
			{
				game.pointer.y = (game.pointer.y - 1 + 3) % 3;
				return USER__POINTER_MOVEMENT;
			}
			case 'S':
			case 's':
			{
				game.pointer.y = (game.pointer.y + 1) % 3;
				return USER__POINTER_MOVEMENT;
			}
			default:
				return USER__INVALID_INPUT;
			}
			break;
		}
		case GAME_MENU_SCREEN_2:
		{
			switch (input_character)
			{
			case ' ':
			{
				if (game.pointer.y == 0) {
					game.user_token = TOKEN_X;
					game.computer_token = TOKEN_O;
					return USER__NEXT_MENU_PAGE;
				}
				else if (game.pointer.y == 1) {
					game.user_token = TOKEN_O;
					game.computer_token = TOKEN_X;
					return USER__NEXT_MENU_PAGE;
				}
				else {
					return USER__PREVIOUS_MENU_PAGE;
				}
			}
			case 'W':
			case 'w':
			{
				game.pointer.y = (game.pointer.y - 1 + 3) % 3;
				return USER__POINTER_MOVEMENT;
			}
			case 'S':
			case 's':
			{
				game.pointer.y = (game.pointer.y + 1) % 3;
				return USER__POINTER_MOVEMENT;
			}
			default:
				return USER__INVALID_INPUT;
			}
			break;
		}
		case GAME_MENU_SCREEN_3:
		{
			switch (input_character)
			{
			case ' ':
			{
				if (game.pointer.y == 0) {
					game.difficulty = HARD;
					return USER__ALL_SETTINGS_COMPLETED;
				}
				else if (game.pointer.y == 1) {
					game.difficulty = MEDIUM;
					return USER__ALL_SETTINGS_COMPLETED;
				}
				else if (game.pointer.y == 2) {
					game.difficulty = EASY;
					return USER__ALL_SETTINGS_COMPLETED;
				}
				else {
					return USER__PREVIOUS_MENU_PAGE;
				}
			}
			case 'W':
			case 'w':
			{
				game.pointer.y = (game.pointer.y - 1 + 4) % 4;
				return USER__POINTER_MOVEMENT;
			}
			case 'S':
			case 's':
			{
				game.pointer.y = (game.pointer.y + 1) % 4;
				return USER__POINTER_MOVEMENT;
			}
			default:
				return USER__INVALID_INPUT;
			}
		}
		default:
			return USER__MISSED_CASE;
		}
	}

	__USER_ACTION UserHandler::input_on_game_screen(Game_Data &game)
	{
		std::cout << " ";

		char input_character = _getch();

		switch (input_character) {
		case 'W':
		case 'w':
			if (game.pointer.y > 0) {
				game.pointer.y--;
				return USER__POINTER_MOVEMENT;
			}
			else {
				return USER__MOVE_REQUEST_OUT_OF_RANGE_TOP;
			}
		case 'S':
		case 's':
			if (game.pointer.y < game.board_size - 1) {
				game.pointer.y++;
				return USER__POINTER_MOVEMENT;
			}
			else {
				return USER__MOVE_REQUEST_OUT_OF_RANGE_BOTTOM;
			}
		case 'A':
		case 'a':
			if (game.pointer.x > 0) {
				game.pointer.x--;
				return USER__POINTER_MOVEMENT;
			}
			else {
				return USER__MOVE_REQUEST_OUT_OF_RANGE_LEFT;
			}
		case 'D':
		case 'd':
			if (game.pointer.x < game.board_size - 1) {
				game.pointer.x++;
				return USER__POINTER_MOVEMENT;
			}
			else {
				return USER__MOVE_REQUEST_OUT_OF_RANGE_RIGHT;
			}
		case 'H':
		case 'h':
			return USER__HINT;
		case ' ':
			return USER__FILL_REQUEST;
		}

		return EXIT_FAILURE;
	}

}