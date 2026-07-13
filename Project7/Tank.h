#ifndef _TANK_H_
#define _TANK_H_
#include "Game.h"
#include "Item.h"
#include <cstdlib>
#include <ctime>


class Tank : public Item {
    bool disapper;
public:
    Tank(Game* g, size_t r, size_t c) : Item(g, r, c), direction(true), disapper(0){}
    void destroy();
    bool noexist() const { return disapper; }
    void update(int);
    bool out();
    bool direction;
};
#endif
