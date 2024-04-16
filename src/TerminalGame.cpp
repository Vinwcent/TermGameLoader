#include "TerminalGame.hpp"

namespace games {

TerminalGame::TerminalGame(WINDOW *window, std::atomic<bool> &running, std::atomic<bool> &stop)
  : window_(window), running_(running), stop_(stop) {}

}
