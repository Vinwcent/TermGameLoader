#pragma once

#include <ncurses.h>
#include <optional>

namespace games {

class TerminalGame {
public:
  TerminalGame(WINDOW *window);
  virtual void update(char inputChar) = 0;

protected:
  WINDOW *window_;
};

}
