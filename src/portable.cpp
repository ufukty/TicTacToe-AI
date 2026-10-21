#ifdef _WIN32
int GetChar() { return _getch() }
#else
#include <termios.h>
#include <unistd.h>
int GetChar() {
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

#ifndef _WIN32
#include <chrono>
#include <thread>
void Sleep(int ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }
#endif

#ifdef _WIN32
void Clean() { System("cls") }
#else
#include <iostream>
void Clean() { std::cout << "\033[2J\033[H"; }
#endif