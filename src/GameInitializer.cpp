#include <ncurses.h>
#include <thread>

#include "GameInitializer.hpp"

namespace engine {

void GameInitializer::runGame(std::atomic<bool> &running) {
  initWindow_();

  int position = 0;
  while (running) {
    wclear(window_);
    mvwprintw(window_, position, 0, "\uEE00");
    wrefresh(window_);

    int ch = getch();
    if (ch != ERR) {
      position-=10;
    } else {
      position+=2;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  closeWindow_();
}


void GameInitializer::initWindow_() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, true);
  nodelay(stdscr, true);
  timeout(0);

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
