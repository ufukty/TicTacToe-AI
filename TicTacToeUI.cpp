#include <iostream>
#include <math.h>
#include <functional>
#include <Windows.h>
#include <stdlib.h>		// srand, rand
#include <time.h>		// time
#include <string>

#include "TicTacToeUI.h"
#include "TicTacToeBoard.h"

namespace TicTacToe {

	UI::UI(void)
	{
		;
	}

	void UI::prepare_for_start(void) {
		message_flag = false;
	}

	template <typename T>
	void UI::set_scene(T &callback, int iteration, int interval)
	{
		for (int frame = 0; frame < iteration; frame++) {
			system("cls");
			callback((double)frame / (double)iteration);
			Sleep(interval);
		}
	}

	void UI::repeat_print(int t, char c = ' ') {
		for (int i = 0; i < t; i++) std::cout << c;
	}

	void UI::repeat_str(std::string &str, int t, char c = ' ') {
		for (int i = 0; i < t; i++) str += c;
	}

	void UI::centered(std::string &text) {
		repeat_print((CONSOLE_WIDTH - text.length()) / 2);
		std::cout << text;
	}

	void UI::header(Game_Data &game)
	{
		std::string left = "";
		if (game.overall_score.computer + game.overall_score.user == 0) {
			left += "YENI OYUN";
		}
		else {
			left += "KULLANICI ( ";
			left += std::to_string(game.overall_score.user);
			left += " - ";
			left += std::to_string(game.overall_score.computer);
			left += " ) BILGISAYAR";
		}
		std::string right = "KLAVYE: W, A, S, D, BOSLUK, H";

		std::cout << "\n";
		repeat_print(5);
		std::cout << left;
		int space_count = CONSOLE_WIDTH - left.length() - right.length() - 10;
		repeat_print(space_count);
		std::cout << right << "\n";
		repeat_print(95, '_');
	}

	void UI::render_opening_screen(void)
	{

		set_scene([](double f) -> void {
			auto t = [](double t, int line_number) -> char {

				const char tones[] = { ' ', '.', '_', ';', 'ö', '*', '&', '+', (char)254, (char)220 };
				double fade = pow(sin(t * 3.1415926535 * 0.5 * 1.2 * ((double)line_number / 50 + 1)), 3);
				return fade > 0 ? tones[(unsigned int)((fade * 9.99))] : tones[0];

			};

			auto r = []() -> char {
				return (rand() % 100 < 50) ? (char)13 : (char)' '; // 13: carriage return
			};

			std::cout << "\n";
			std::cout << "\n";
			std::cout << "      " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << "  " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << "    " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << "         " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << "   " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << "       " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << " \n";
			std::cout << "      " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "  " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "  " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "       " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "   " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "     " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "\n";
			std::cout << "           " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "       " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << " " << r() << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "     " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "            " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "       " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "    " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "     " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "\n";
			std::cout << "           " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "       " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "  " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "                     " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "       " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << " " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "    " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "\n";
			std::cout << "           " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "       " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "  " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "                     " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "      " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << " " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "   " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "        \n";
			std::cout << "           " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "      " << r() << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "  " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "                     " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "      " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "   " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "   " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "        \n";
			std::cout << "           " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "       " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "  " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "     " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "            " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "     " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "  " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "     " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "\n";
			std::cout << "           " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "       " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "  " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "            " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "     " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "  " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "\n";
			std::cout << "           " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "       " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "    " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "              " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "    " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "     " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "   " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << " \n";
			std::cout << "                                                                                           \n";
			std::cout << "                          " << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << "    " << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << "    " << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << "                     \n";
			std::cout << "                          " << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << "  " << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << "  " << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << "                     \n";
			std::cout << "                               " << t(f, 12) << t(f, 12) << t(f, 12) << t(f, 12) << "       " << t(f, 12) << t(f, 12) << t(f, 12) << t(f, 12) << "     " << t(f, 12) << t(f, 12) << t(f, 12) << t(f, 12) << "  " << t(f, 12) << t(f, 12) << t(f, 12) << t(f, 12) << "                             \n";
			std::cout << "                               " << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << "       " << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << "     " << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << "  " << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << "                        \n";
			std::cout << "                              " << r() << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << "       " << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << "     " << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << "  " << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << "                        \n";
			std::cout << "                               " << t(f, 15) << t(f, 15) << t(f, 15) << t(f, 15) << "       " << t(f, 15) << t(f, 15) << t(f, 15) << t(f, 15) << "     " << t(f, 15) << t(f, 15) << t(f, 15) << t(f, 15) << "  " << t(f, 15) << t(f, 15) << t(f, 15) << t(f, 15) << "                             \n";
			std::cout << "                               " << t(f, 16) << t(f, 16) << t(f, 16) << t(f, 16) << "       " << t(f, 16) << t(f, 16) << t(f, 16) << t(f, 16) << "     " << t(f, 16) << t(f, 16) << t(f, 16) << t(f, 16) << "  " << t(f, 16) << t(f, 16) << t(f, 16) << t(f, 16) << "                             \n";
			std::cout << "                               " << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << "       " << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << "  " << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << "\n";
			std::cout << "                               " << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << "         " << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << "    " << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << "\n";
		}, 50, 5);

		set_scene([](double f) -> void {
			auto t = [](double t, int line_number) -> char {

				char tones[] = { ' ', (char)176, (char)177, (char)178, (char)219 };
				double fade = pow(sin(t * 3.1415926535 * 0.5 * (-(double)line_number / 50 + 1) + 3.1415926535 / 2), 3);
				return fade > 0 ? tones[(unsigned int)((fade * 4.99))] : tones[0];

			};

			std::cout << "\n";
			std::cout << "\n";
			std::cout << "      " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << "  " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << "    " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << "         " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << "   " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << "       " << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << t(f, 0) << " \n";
			std::cout << "      " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "  " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "  " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "       " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "   " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "     " << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << t(f, 1) << "\n";
			std::cout << "           " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "       " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "  " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "     " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "            " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "       " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "    " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "     " << t(f, 2) << t(f, 2) << t(f, 2) << t(f, 2) << "\n";
			std::cout << "           " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "       " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "  " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "                     " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "       " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << " " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "    " << t(f, 3) << t(f, 3) << t(f, 3) << t(f, 3) << "\n";
			std::cout << "           " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "       " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "  " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "                     " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "      " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << " " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "   " << t(f, 4) << t(f, 4) << t(f, 4) << t(f, 4) << "        \n";
			std::cout << "           " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "       " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "  " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "                     " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "      " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "   " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "   " << t(f, 5) << t(f, 5) << t(f, 5) << t(f, 5) << "        \n";
			std::cout << "           " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "       " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "  " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "     " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "            " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "     " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "  " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "     " << t(f, 6) << t(f, 6) << t(f, 6) << t(f, 6) << "\n";
			std::cout << "           " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "       " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "  " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "            " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "     " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "  " << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << t(f, 7) << "\n";
			std::cout << "           " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "       " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "    " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "              " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "    " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "     " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << "   " << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << t(f, 8) << " \n";
			std::cout << "                                                                                           \n";
			std::cout << "                          " << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << "    " << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << "    " << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << t(f, 10) << "                     \n";
			std::cout << "                          " << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << "  " << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << "  " << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << t(f, 11) << "                     \n";
			std::cout << "                               " << t(f, 12) << t(f, 12) << t(f, 12) << t(f, 12) << "       " << t(f, 12) << t(f, 12) << t(f, 12) << t(f, 12) << "     " << t(f, 12) << t(f, 12) << t(f, 12) << t(f, 12) << "  " << t(f, 12) << t(f, 12) << t(f, 12) << t(f, 12) << "                             \n";
			std::cout << "                               " << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << "       " << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << "     " << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << "  " << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << t(f, 13) << "                        \n";
			std::cout << "                               " << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << "       " << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << "     " << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << "  " << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << t(f, 14) << "                        \n";
			std::cout << "                               " << t(f, 15) << t(f, 15) << t(f, 15) << t(f, 15) << "       " << t(f, 15) << t(f, 15) << t(f, 15) << t(f, 15) << "     " << t(f, 15) << t(f, 15) << t(f, 15) << t(f, 15) << "  " << t(f, 15) << t(f, 15) << t(f, 15) << t(f, 15) << "                             \n";
			std::cout << "                               " << t(f, 16) << t(f, 16) << t(f, 16) << t(f, 16) << "       " << t(f, 16) << t(f, 16) << t(f, 16) << t(f, 16) << "     " << t(f, 16) << t(f, 16) << t(f, 16) << t(f, 16) << "  " << t(f, 16) << t(f, 16) << t(f, 16) << t(f, 16) << "                             \n";
			std::cout << "                               " << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << "       " << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << "  " << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << t(f, 17) << "\n";
			std::cout << "                               " << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << "         " << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << "    " << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << t(f, 18) << "\n";
		}, 50, 5);

		system("cls");
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                        Ufuk Tan - 2017";
		Sleep(1000);
		system("cls");
	}

	void UI::render_menu_screen(Game_Data &game)
	{
		char t = (char)254;

		system("cls");
		header(game);

		if (game.status == GAME_MENU_SCREEN_1) {

			repeat_print(6, '\n');
			std::string command = "Oyun tahtasi icin boyut secin";
			centered(command);

			repeat_print(3, '\n');
			std::string option1 = "[";
			option1 += ((game.pointer.y == 0) ? t : ' ');
			option1 += "] 3x3";
			centered(option1);

			std::cout << "\n\n";
			std::string option2 = "[";
			option2 += ((game.pointer.y == 1) ? t : ' ');
			option2 += "] 4x4";
			centered(option2);

			std::cout << "\n\n";
			std::string option3 = "[";
			option3 += ((game.pointer.y == 2) ? t : ' ');
			option3 += "] 5x5";
			centered(option3);

		}
		else if (game.status == GAME_MENU_SCREEN_2) {

			repeat_print(6, '\n');
			std::string command = "Tas secin (X once baslar)";
			centered(command);

			repeat_print(3, '\n');
			std::string option1 = "[";
			option1 += ((game.pointer.y == 0) ? t : ' ');
			option1 += "] X";
			centered(option1);

			repeat_print(2, '\n');
			std::string option2 = "[";
			option2 += ((game.pointer.y == 1) ? t : ' ');
			option2 += "] O";
			centered(option2);

			repeat_print(3, '\n');
			std::string option3 = "[";
			option3 += ((game.pointer.y == 2) ? t : ' ');
			option3 += "] Geri";
			centered(option3);

		}
		else if (game.status == GAME_MENU_SCREEN_3) {

			repeat_print(5, '\n');
			std::string command = "Zorluk seviyesini secin";
			centered(command);

			repeat_print(3, '\n');
			std::string option1 = "[";
			option1 += ((game.pointer.y == 0) ? t : ' ');
			option1 += "] Zor  ";
			centered(option1);

			repeat_print(2, '\n');
			std::string option2 = "[";
			option2 += ((game.pointer.y == 1) ? t : ' ');
			option2 += "] Orta ";
			centered(option2);

			repeat_print(2, '\n');
			std::string option3 = "[";
			option3 += ((game.pointer.y == 2) ? t : ' ');
			option3 += "] Kolay";
			centered(option3);

			repeat_print(3, '\n');
			std::string option4 = "[";
			option4 += ((game.pointer.y == 3) ? t : ' ');
			option4 += "] Geri";
			centered(option4);

		}
	}

	void UI::print_board(Board &board, Game_Data &game)
	{
		char t[] = { (char)196, (char)179, (char)197, (char)218, (char)194, (char)191, (char)180, (char)217, (char)193, (char)192, (char)195 };
		std::string row = "";

		auto field = [&](int y, int x) {
			char field;
			switch (board.get(y, x)) {
			case TOKEN_X:
				field = 'X';
				break;
			case TOKEN_O:
				field = 'O';
				break;
			case TOKEN_EMPTY:
			default:
				field = ' ';
				break;
			}
			bool pointer_on_field = game.pointer.y == y && game.pointer.x == x;
			row += pointer_on_field ? " [ " : "   ";
			row += field;
			row += pointer_on_field ? " ] " : "   ";
		};
		auto row_type_a = [&]() {
			std::cout << "\n\n";
			row = "";
			row += t[3];
			for (int i = 1; i < game.board_size; i++) {
				repeat_str(row, 7, t[0]);
				row += t[4];
			}
			repeat_str(row, 7, t[0]);
			row += t[5];
			centered(row);
		};
		auto row_type_b = [&]() {
			std::cout << "\n";
			row = "";
			row += t[1];
			for (int i = 1; i < game.board_size; i++) {
				repeat_str(row, 7, ' ');
				row += t[1];
			}
			repeat_str(row, 7, ' ');
			row += t[1];
			centered(row);
		};
		auto row_type_c = [&](int row_number) {
			std::cout << "\n";
			row = "";
			row += t[1];
			for (int column_number = 1; column_number < game.board_size; column_number++) {
				field(row_number, column_number - 1);
				row += t[1];
			}
			field(row_number, game.board_size - 1);
			row += t[1];
			centered(row);
		};
		auto row_type_d = [&]() {
			std::cout << "\n";
			row = "";
			row += t[10];
			for (int i = 1; i < game.board_size; i++) {
				repeat_str(row, 7, t[0]);
				row += t[2];
			}
			repeat_str(row, 7, t[0]);
			row += t[6];
			centered(row);
		};
		auto row_type_e = [&]() {
			std::cout << "\n";
			row = "";
			row += t[9];
			for (int i = 1; i < game.board_size; i++) {
				repeat_str(row, 7, t[0]);
				row += t[8];
			}
			repeat_str(row, 7, t[0]);
			row += t[7];
			centered(row);
		};

		row_type_a();
		for (int row_number = 1; row_number < game.board_size; row_number++) {
			row_type_b();
			row_type_c(row_number - 1);
			row_type_b();
			row_type_d();
		}
		row_type_b();
		row_type_c(game.board_size - 1);
		row_type_b();
		row_type_e();

	}

	void UI::display_message(const char str[])
	{
		this->message.assign(str);
		message_flag = true;
	}

	void UI::render_game_screen(Board &board, Game_Data &game)
	{
		system("cls");

		header(game);

		repeat_print((5 - game.board_size) * 2 - 1, '\n');

		print_board(board, game);

		if (message_flag) {
			std::cout << "\n";
			centered(message);
			message_flag = false;
		}
	}

}