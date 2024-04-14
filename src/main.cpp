#include "GameLoader.hpp"
#include <curses.h>


int main() {
  GameLoader loader;
  loader.start();
  std::this_thread::sleep_for(std::chrono::seconds(100));
  loader.end();
  return 0;
}
