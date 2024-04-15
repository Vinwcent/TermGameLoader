#pragma once

namespace games {
namespace helicopter {

struct TilePosition {
  int x;
  int y;

  TilePosition operator+(const TilePosition& other) const {
      TilePosition result;
      result.x = this->x + other.x;
      result.y = this->y + other.y;
      return result;
  }
};

struct Size {
  int width;
  int height;
};


}
}
