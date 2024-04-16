#include <iostream>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>

#include "GameLoader.hpp"
#include "GameInitializer.hpp"

void setupTerminal(struct termios &old_tio) {
  struct termios new_tio;
  tcgetattr(STDIN_FILENO,
            &old_tio); // Sauvegarder les paramètres actuels du terminal

  new_tio = old_tio;
  new_tio.c_lflag &=
      (~ICANON & ~ECHO); // Désactiver le mode canonique et l'écho
  tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

void restoreTerminal(struct termios &old_tio) {
  tcsetattr(STDIN_FILENO, TCSANOW,
            &old_tio); // Restaurer les paramètres du terminal
}

GameLoader::GameLoader(char gameKey, std::string loadingString,
                       std::vector<std::string> spinner, float spinTime)
    : running_(false), gameKey_(gameKey), loadingString_(loadingString),
      spinner_(spinner), spinTime_(spinTime) {}

void GameLoader::start() {
  running_ = true;
  loadingThread_ = std::thread(&GameLoader::loading_, this);
}

void GameLoader::end() {
  running_ = false;
  stopSpinner_.store(true);
  loadingThread_.join();
  std::cout << "\n  ->Done !\n";
}

void GameLoader::loading_() {
  stopSpinner_ = false;

  // Thread to take inputs while spinning
  std::thread inputThread([this]() { takeInputs_(stopSpinner_); });


  // Setup terminal
  struct termios old_tio;
  setupTerminal(old_tio);

  // Spin while key has not been pressed
  int spinIndex = 0;
  while (!stopSpinner_.load()) {
    spinIndex = (spinIndex + 1) % spinner_.size();
    std::cout << "\r" << loadingString_ << " " << spinner_[spinIndex] << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  // Close spin
  inputThread.join();
  restoreTerminal(old_tio);

  if (running_) {
    initializer_.runGame(running_);
  }
}

void GameLoader::takeInputs_(std::atomic<bool>& stopInput) {
    char c;
    while (!stopInput.load()) {
        fd_set set;
        struct timeval timeout;

        FD_ZERO(&set);          // Clear the set
        FD_SET(STDIN_FILENO, &set);  // Add our file descriptor to the set

        timeout.tv_sec = 0;     // Set a timeout
        timeout.tv_usec = 100000;  // 100 ms

        int result = select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout);
        if (result == -1) {
            // Error
            break;
        } else if (result == 0) {
            // Timeout, no data
        } else {
            if (FD_ISSET(STDIN_FILENO, &set)) {
                std::cin >> c;
                if (c == gameKey_) {
                    stopInput.store(true);
                    break;
                }
            }
        }

        if (stopInput.load()) break;
    }
}
