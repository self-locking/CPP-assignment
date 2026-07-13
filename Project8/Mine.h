#ifndef _MINE_H_
#define _MINE_H_
#include "RemovableItem.h"
#include "Game.h"
#include "Item.h"
#include"SuperTank.h"

class Mine : public RemovableItem {
public:
    Mine (Game* g, size_t r, size_t c, int dx1, int dy1) : RemovableItem(g, r, c, dx1, dy1) {}
    void update(int);
    bool out();
};
#endif
