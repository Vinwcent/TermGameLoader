#pragma once
#include <curses.h>
#include <vector>
#include <string>

#include "utils.hpp"

namespace games {
namespace helicopter {


class GameObject {
public:
  virtual void printOn(WINDOW *window) = 0;
  void setPosition(TilePosition position);
  TilePosition getPosition() const;
protected:
  TilePosition position_;
  Size size_;
};


class Helicopter : public GameObject {
public:
  void printOn(WINDOW *window) override;
private:
  int frame = 0;
  std::vector<std::string> backBlade_ {"\\", "|", "/", "-"};
  std::string getBackBladesChar_();
};


enum class WallAnchor {
  TOP,
  BOTTOM
};

class Wall : public GameObject {
public:
  Wall(int size, WallAnchor anchor);
  void printOn(WINDOW *window) override;
  void setSize(int size);
  int getSize() const;
  WallAnchor getWallAnchor() const;
  bool isTouching(TilePosition position);
private:
  WallAnchor anchor_;
  int size_;
};


}
}