#ifndef _COIN_H_
#define _COIN_H_
#include "Game.h"
#include "Item.h"

class Coin : public Item {
public:
    Coin(Game* g, size_t r, size_t c) : Item(g, r, c) {}
    void update(int);
    bool out();
};
#endif
