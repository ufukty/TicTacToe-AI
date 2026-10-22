#include "portable.h"

#ifdef _WIN32
#include "Windows.h"
#include "conio.h"
void Clean() { System("cls") }
int  GetChar() { return _getch() }
#endif

#ifndef _WIN32
#include <chrono>
#include <iostream>
#include <termios.h>
#include <thread>
#include <unistd.h>
void Sleep(int ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }
void Clean() { std::cout << "\033[2J\033[H"; }
int  GetChar() {
  termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt); // save current settings
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO); // no line buffering, no echo
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  unsigned char ch = 0;
  read(STDIN_FILENO, &ch, 1); // wait for one byte

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore settings
  return ch;
}

#endif