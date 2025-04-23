#include <stdint.h>

typeof struct {
  uint8_t x, y;
} Vector2;

typeof struct {
  uint8_t x, y;
  uint8_t value; // Yes, this is just indexed from a table in this version

  Vector2 previousPosition;
  Vector2 mergedFrom; // Tracks tiles that merged together
} Tile;

void Tile_savePosition(Tile* t, Vector2 prevPos) {
  t->previousPosition = prevPos;
}

void Tile_updatePosition(Tile* t, Vector2 position) {
  t->x = position.x;
  t->y = position.y;
}

/*Tile.prototype.serialize = function () {
  return {
    position: {
      x: this.x,
      y: this.y
    },
    value: this.value
  };
};*/ // snipped off the sides, javascript bs
