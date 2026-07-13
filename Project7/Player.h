#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Game.h"
#include "Item.h"

class Player : public Item {
    int direction;
    int location;
public:
    Player(Game* g, size_t r = 12, size_t c = 25) : Item(g, r, c), direction(0), location(0) {}
    void update(int key);
    bool out();
};
#endif
