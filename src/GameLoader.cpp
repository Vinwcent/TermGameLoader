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
  if (loadingThread_.joinable()) {
    loadingThread_.join();
  }
}

void GameLoader::loading_() {
  std::atomic<bool> stopSpinner(false);

  // Thread to take inputs while spinning
  std::thread inputThread([&stopSpinner, this]() { takeInputs_(stopSpinner); });

  // Setup terminal
  struct termios old_tio;
  setupTerminal(old_tio);

  // Spin while key has not been pressed
  int spinIndex = 0;
  while (!stopSpinner.load()) {
    spinIndex = (spinIndex + 1) % spinner_.size();
    std::cout << "\r" << loadingString_ << " " << spinner_[spinIndex] << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  // Close spin
  inputThread.join();
  restoreTerminal(old_tio);

  engine::GameInitializer initializer;
  initializer.runGame(running_);

}

void GameLoader::takeInputs_(std::atomic<bool> &stopInput) {
  char c;
  while (!stopInput.load()) {
    // Lire l'entrée utilisateur
    if (std::cin >> c && c == gameKey_) {
      stopInput.store(true); // Arrêter l'entrée utilisateur
      break;
    }
  }
}
