/*
TicTacToe-v2.1-EN

Ufuk Tan
github.com/ufukty

Gameplay available at https://youtu.be/X9GnQvv_bo4

GNU General Public License v3.0
*/

#pragma once

#define CONSOLE_WIDTH 95

#define UNDEFINED 60

#define POSITIVE_INFINITY 999999
#define NEGATIVE_INFINITY -999999

/////////////////////////////////// Board

#define __SEAL_RESPONSE int
#define SEAL_SUCCESS 300
#define SEAL_NOT_YOUR_TURN 310
#define SEAL_OUT_OF_RANGE 320
#define SEAL_ALREADY_SEALED 330
#define SEAL_FAILURE 340

#define __BOARD_SIZE unsigned __int8
#define BOARD_SIZE_3x3 3
#define BOARD_SIZE_4x4 4
#define BOARD_SIZE_5x5 5
#define BOARD_LOWER_LIMIT 3
#define BOARD_UPPER_LIMIT 5

#define __TOKEN int
#define TOKEN_X 10
#define TOKEN_O 20
#define TOKEN_MIXED 30
#define TOKEN_EMPTY 40
#define TOKEN_INITIAL 50
#define TOKEN_AUTO 60

#define __BOARD_STATE int
#define BOARD_STATE__X_WIN 200
#define BOARD_STATE__O_WIN 210
#define BOARD_STATE__DRAW 220
#define BOARD_STATE__PLAYING 230
#define BOARD_STATE__EMPTY 240
#define BOARD_STATE__NOT_CALCULATED 250

///////////////////////////////////  TicTacToe (class)

#define __GAME_STATUS int
#define GAME_INITIALIZED 10
#define GAME_WELCOME_SCREEN 20
#define GAME_MENU_SCREEN_1 30
#define GAME_MENU_SCREEN_2 31
#define GAME_MENU_SCREEN_3 32
#define GAME_MENU_COMPLETED 39
#define GAME_PLAYING 40
#define GAME_ENDED_DRAW 50
#define GAME_ENDED_COMPUTER_WIN 51
#define GAME_ENDED_USER_WIN 52
#define GAME_ABOUT_TO_RESTART 60
#define GAME_FINISHED 70


///////////////////////////////////  (UserHandler)

#define __USER_ACTION int

#define USER__PREVIOUS_MENU_PAGE 10
#define USER__NEXT_MENU_PAGE 20
#define USER__ALL_SETTINGS_COMPLETED 30
#define USER__POINTER_MOVEMENT 40
#define USER__INVALID_INPUT 50
#define USER__OPPONENTS_ROUND 60
#define USER__FILL_REQUEST 70
#define USER__MOVE_REQUEST_OUT_OF_RANGE_TOP 80
#define USER__MOVE_REQUEST_OUT_OF_RANGE_LEFT 81
#define USER__MOVE_REQUEST_OUT_OF_RANGE_RIGHT 82
#define USER__MOVE_REQUEST_OUT_OF_RANGE_BOTTOM 83
#define USER__MISSED_CASE 90
#define USER__HINT 100

////////////////////////////////// Decision

#define __DIFFICULTY __int8
#define HARD 10
#define MEDIUM 20
#define EASY 30

#define __DECISION_RESPONSE int
#define TREE_NOT_FOUND 500

//////////////////////////////// AlphaBetaDetails

