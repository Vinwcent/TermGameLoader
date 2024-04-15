#include <ncurses.h>
#include <thread>

#include "GameInitializer.hpp"
#include "src/games/HelicopterGame.hpp"

namespace engine {

void GameInitializer::runGame(std::atomic<bool> &running) {
  initWindow_();

  games::HelicopterGame game(window_);

  int position = 0;
  while (running) {
    int ch = getch();
    game.update(ch);
  }

  closeWindow_();
}


void GameInitializer::initWindow_() {
  initscr();
  cbreak();
  noecho();
  nodelay(stdscr, true);
  timeout(100);

  int termHeight, termWidth;
  getmaxyx(stdscr, termHeight, termWidth);
  window_ = newwin(termHeight, termWidth, 0, 0);
  box(window_, 0, 0);
}

void GameInitializer::closeWindow_() {
  if (window_) {
    delwin(window_);
  }
  endwin();
}

}
