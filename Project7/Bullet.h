#ifndef _BULLET_H_
#define _BULLET_H_
#include "Game.h"
#include "Item.h"

class Bullet : public Item{
public:
    Bullet(Game* g, size_t r, size_t c) : Item(g, r, c) {}
    void update(int);
    bool out();
};
#endif
 