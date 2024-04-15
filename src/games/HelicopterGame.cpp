#include <iostream>
#include <random>
#include <sstream>

#include "HelicopterGame.hpp"

namespace games {

HelicopterGame::HelicopterGame(WINDOW *window) : TerminalGame(window) {
  initGame_();
}

void HelicopterGame::update(char inputChar) {
  updateHelicopterPosition_(inputChar);
  wclear(window_);
  updateWalls_();
  updateObstacles_();
  helicopter_.printOn(window_);
  updateScore_();
  wrefresh(window_);
}

void HelicopterGame::initGame_() {
  getmaxyx(stdscr, termHeight_, termWidth_);
  helicopter_.setPosition({termWidth_ / 6, termHeight_ / 2});

  maxHoleSize_ = termHeight_ / 1.5;
  minHoleSize_ = maxHoleSize_ / 2;
  currentSizeBot_ = (termHeight_ - maxHoleSize_) / 2;
  currentSizeTop_ = (termHeight_ - maxHoleSize_) / 2;

  for (int i = 0; i < termWidth_; ++i) {
    auto newBotWall = std::make_unique<helicopter::Wall>(currentSizeBot_, helicopter::WallAnchor::BOTTOM);
    newBotWall->setPosition({i, termHeight_ - 1});

    auto newTopWall = std::make_unique<helicopter::Wall>(currentSizeTop_, helicopter::WallAnchor::TOP);
    newTopWall->setPosition({i, 0});

    walls_.push_back(std::move(newBotWall));
    walls_.push_back(std::move(newTopWall));
  }

  obstacles_.push_back(std::make_unique<helicopter::Wall>(7, helicopter::WallAnchor::BOTTOM));
  obstacles_.push_back(std::make_unique<helicopter::Wall>(7, helicopter::WallAnchor::BOTTOM));
}

void HelicopterGame::restartGame_() {
  score_ = 0;
  helicopter_.setPosition({termWidth_ / 6, termHeight_ / 2});
  currentSizeBot_ = (termHeight_ - maxHoleSize_) / 2;
  currentSizeTop_ = (termHeight_ - maxHoleSize_) / 2;
  for (int i = 0; i < termWidth_; ++i) {
    helicopter::Wall *wall1 = walls_[2*i].get();
    helicopter::Wall *wall2 = walls_[2*i+1].get();
    wall1->setSize(currentSizeBot_);
    wall1->setPosition({i, termHeight_ - 1});
    wall2->setSize(currentSizeTop_);
    wall2->setPosition({i, 0});
  }
  obstacles_[0]->setPosition({-10, 0});
  obstacles_[1]->setPosition({-11, 0});
}

void HelicopterGame::updateHelicopterPosition_(char inputChar) {
  helicopter::TilePosition newPosition;
  if (inputChar != ERR) {
    newPosition = helicopter::TilePosition{0, -1} + helicopter_.getPosition();
  } else {
    newPosition = helicopter::TilePosition{0, 1} + helicopter_.getPosition();
  }
  helicopter_.setPosition(newPosition);
}

void HelicopterGame::updateWalls_() {
  for (auto &wall : walls_) {

    if (wall->isTouching(helicopter_.getPosition())) {
      restartGame_();
      return;
    }

    auto newPosition = wall->getPosition() + helicopter::TilePosition{-3, 0};
    if (newPosition.x < 0) {
      newPosition.x += termWidth_;
      recycleWall(wall.get());
    }

    wall->setPosition(newPosition);
    wall->printOn(window_);
  }
}

void HelicopterGame::updateObstacles_() {
  for (auto &obs : obstacles_) {
    auto newPosition = obs->getPosition() + helicopter::TilePosition{-3, 0};
    if (newPosition.x > 0) {
      obs->setPosition(newPosition);
    } else {
      obstacleUsed = false;
    }
    obs->printOn(window_);
  }
}

void HelicopterGame::setObstacle_(int x) {
  obstacleUsed = true;
  int holeSize = termHeight_ - currentSizeBot_ - currentSizeTop_;
  int holeCenter = holeSize / 2 + currentSizeTop_;
  obstacles_[0]->setPosition({x, holeCenter});
  obstacles_[1]->setPosition({x + 1, holeCenter});
}

void HelicopterGame::recycleWall(helicopter::Wall *wall) {
  int offset;

  if (bernouilliSign(prob_)) {
    offset = 1;
  } else {
    offset = -1;
  }

  bool moveCenter = bernouilliSign(prob_);
  if (moveCenter) {
    // Move the hole
    int newSizeBot = currentSizeBot_ + offset;
    int newSizeTop = currentSizeTop_ - offset;
    if (newSizeBot > 0 &&
        newSizeTop > 0) {
      currentSizeBot_ = newSizeBot;
      currentSizeTop_ = newSizeTop;
    }
  } else {
    // Change the hole size between holes
    int newSizeBot = currentSizeBot_ + offset;
    int newSizeTop = currentSizeTop_ + offset;
    int holeSize = termHeight_ - newSizeBot - newSizeTop;
    if (newSizeBot > 0 &&
        newSizeTop > 0 &&
        holeSize > minHoleSize_ &&
        holeSize < maxHoleSize_) {
      currentSizeBot_ = newSizeBot;
      currentSizeTop_ = newSizeTop;
      if (holeSize > 5 && !obstacleUsed) {
        setObstacle_(termWidth_);
      }
    }
  }

  switch (wall->getWallAnchor()) {
  case helicopter::WallAnchor::TOP:
    wall->setSize(currentSizeTop_);
    break;
  case helicopter::WallAnchor::BOTTOM:
    wall->setSize(currentSizeBot_);
    break;
  }
}

int HelicopterGame::bernouilliSign(double p) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::bernoulli_distribution dis(p);

  return dis(gen);
}

void HelicopterGame::updateScore_() {
  score_ += 1;
  std::stringstream ss;
  ss << score_;
  std::string str = ss.str();
  auto helicoPosition = helicopter_.getPosition();
  mvwprintw(window_, helicoPosition.y - 3, helicoPosition.x, str.c_str());
}

} // namespace games
