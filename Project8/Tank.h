#ifndef _TANK_H_
#define _TANK_H_
#include "Game.h"
#include "Item.h"

class Tank: public Item {
protected:
    int health;
    int updateCount;
    Game* game;
public:
    Tank (Game* g) : game(g) {}
    void update(int key) =0;
    int reportHealth() {return health;}
    /*virtual int reportNumBullet() {return 0;};*/
    /*virtual bool isHit(int r, int w, int range) = 0;*/
    virtual void reduceHealth() =0;
    bool died() { return false; }
    bool out() { return false; }
};
#endif
