#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Game.h"
#include "Item.h"
#include "Tank.h"

#define MAXCOUNT 40
#define MAXNUMBULLET 20

class Player:public Tank {
    int numBullet;
    int updateCount;
public:
    int lastdx;
    int lastdy;
    Player(Game* g) : Tank(g) {
        game = g;
        row = 20;
        col = 25;
        dx = 0;
        dy = 0;
        updateCount = 0;
        numBullet = 20;
        health = 10;
        lastdx = 0;
        lastdy = -1;
    }
    int reportNumBullet() {return numBullet;}
    void update(int key);
    bool out();
    void reduceHealth(); 
    void cureHealth();
    int getdx() { return lastdx; }
    int getdy() { return lastdy; }
    int reportHealth() { return health; }
};
#endif
