#pragma once

#include <ncurses.h>
#include <optional>
#include <vector>

#include "src/TerminalGame.hpp"
#include "src/games/helicopter/GameObject.hpp"

namespace games {

class HelicopterGame : TerminalGame {
public:
  HelicopterGame(WINDOW *window, std::atomic<bool> &running, std::atomic<bool> &stop);
  void update(char inputChar) override;

private:
  helicopter::Helicopter helicopter_;
  std::vector<std::unique_ptr<helicopter::Wall>> walls_ {};
  std::vector<std::unique_ptr<helicopter::Wall>> obstacles_ {};
  int termHeight_;
  int termWidth_;

  int score_ = 0;
  int highScore_ = 0;

  double prob_ = 0.5;
  int currentSizeBot_ = 10;
  int currentSizeTop_ = 10;

  int minHoleSize_ = 20;
  int maxHoleSize_ = 55;

  bool obstacleUsed = false;

  void initGame_();
  void restartGame_();

  void updateHelicopterPosition_(char inputChar);
  void updateWalls_();
  void updateObstacles_();

  void setObstacle_(int x);

  void recycleWall(helicopter::Wall *wall);

  int bernouilliSign(double p);
  void updateScore_();
  void updateDifficulty_();

  void checkRunning();
};







}
