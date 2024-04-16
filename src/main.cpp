#include "GameLoader.hpp"
#include <curses.h>
#include <iostream>


int main() {
  GameLoader loader;
  loader.start();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  loader.end();

//   loader.start();
//   std::cout << "Start the second\n";
//   std::this_thread::sleep_for(std::chrono::seconds(10));
//   loader.end();
  return 0;
}
