#ifndef _BOMB_H_
#define _BOMB_H_
#include "Game.h"
#include "Item.h"

class Bomb : public Item {
public:
    Bomb(Game* g, size_t r, size_t c) : Item(g, r, c) {}
    void update(int);
    bool out();
};
#endif
