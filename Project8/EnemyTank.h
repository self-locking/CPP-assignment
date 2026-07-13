#ifndef _ENEMYTANK_H_
#define _ENEMYTANK_H_
#include "Game.h"
#include "Item.h"

class EnemyTank : public Tank {
public:
    EnemyTank(Game* g) : Tank(g) {}
    void update(int key)=0;
    bool isHit(int r, int w, int range);
    void reduceHealth() =0;
    bool out();
};
#endif
