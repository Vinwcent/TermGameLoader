#pragma once

#include <thread>


class GameLoader {
public:
  GameLoader(
      char gameKey = 'g',
      std::string loadingString = {"Loading, please wait..."},
      std::vector<std::string> spinner = {"|", "/", "-", "\\"},
      float spinTime = 100
      );

  void start();
  void end();

private:
  char gameKey_;
  std::string loadingString_;
  std::vector<std::string> spinner_;
  float spinTime_;


  std::thread loadingThread_;
  std::atomic<bool> running_;

  void loading_();
  void launchBasicSpinner_();

  void takeInputs_(std::atomic<bool> &stopInput);
};
