#pragma once

#include <ncurses.h>
#include <optional>

namespace games {

class TerminalGame {
public:
  TerminalGame(WINDOW *window, std::atomic<bool> &running, std::atomic<bool> &stop);
  virtual void update(char inputChar) = 0;

protected:
  WINDOW *window_;
  std::atomic<bool> &running_;
  std::atomic<bool> &stop_;
};

}
