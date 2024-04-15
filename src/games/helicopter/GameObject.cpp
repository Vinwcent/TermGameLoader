#include "GameObject.hpp"


namespace games {
namespace helicopter {

void GameObject::setPosition(TilePosition position) {
  position_ = position;
}

TilePosition GameObject::getPosition() const {
  return position_;
}

void Helicopter::printOn(WINDOW *window) {
  // Blades
  mvwprintw(window, position_.y - 1, position_.x - 3, "=======");

  // Rotor
  mvwprintw(window, position_.y, position_.x, "X");

  // Cabin
  mvwprintw(window, position_.y + 1, position_.x - 5, "\\-------\\");
  mvwprintw(window, position_.y + 2, position_.x - 1, "|---/");
}

Wall::Wall(int size, WallAnchor anchor) : anchor_(anchor), size_(size) {}

void Wall::printOn(WINDOW *window) {
  int offset = 1;
  if (anchor_ == WallAnchor::BOTTOM) {
    offset = -1;
  }
  for (int i = 0; i < size_; ++i) {
    mvwprintw(window, position_.y + i * offset, position_.x, "|");
  }
}

void Wall::setSize(int size) {
  size_ = size;
}

int Wall::getSize() const {
  return size_;
}

WallAnchor Wall::getWallAnchor() const {
  return anchor_;
}

bool Wall::isTouching(TilePosition position) {
  int offset = 1;
  if (anchor_ == WallAnchor::BOTTOM) {
    offset = -1;
  }
  for (int i = 0; i < size_; ++i) {
    if (position_.x == position.x
        && position_.y + i * offset == position.y) {
      return true;
    }
  }
  return false;
}


}
}
