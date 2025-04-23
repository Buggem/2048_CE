#include <stdint.h>

typedef struct {
  uint8_t x, y;
} Vector2;

typedef struct {
  uint8_t x, y;
  uint16_t value;

  Vector2 prevPos;
  Vector2 mergedFrom; // Tracks tiles that merged together
} Tile;

void Tile_construct(Tile* t, Vector2 pos, uint8_t value) {
  t->x                = pos.x;
  t->y                = pos.y;
  t->value            = value == 1 ? value : 2; // make sure the value can't be less than two so you don't go adding zeros 😂
}

void Tile_savePosition(Tile* t, Vector2 prevPos) {
  t->prevPos = prevPos;
}

void Tile_updatePosition(Tile* t, Vector2 pos) {
  t->x = pos.x;
  t->y = pos.y;
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
