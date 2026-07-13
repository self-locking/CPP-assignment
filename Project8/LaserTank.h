#ifndef _LASERTANK_H_
#define _LASERTANK_H_
#include "Game.h"
#include "Item.h"
#include"Tank.h"
#include"EnemyTank.h"
#include<stdlib.h>
#include<ctime>

class LaserTank :public EnemyTank {
    int lastdx, lastdy;
public:
    LaserTank(Game* g) : EnemyTank(g) {
        int min_row = 10, max_row = 20;
        int min_col = 25, max_col = 40;
        int random_row = rand() % (max_row - min_row + 1) + min_row;
        int random_col = rand() % (max_col - min_col + 1) + min_col;
        row = random_row;
        col = random_row;
        dx = dy = lastdx = 0;
        lastdy = -1;
        health = 3;
        updateCount = 0;
        on = false;
    }
    void update(int key);
    void hit() { on = false; }
    bool died() { return on; }
    void reduceHealth();
    bool out();
    bool on;
};
#endif


