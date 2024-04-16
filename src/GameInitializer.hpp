#pragma once

#include <ncurses.h>

#include <atomic>

namespace engine {

class GameInitializer {

public:
  void runGame(std::atomic<bool> &running);

private:
  void initWindow_();
  void closeWindow_();

  WINDOW *window_;
};

}
