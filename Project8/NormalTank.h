#ifndef _NORMALTANK_H_
#define _NORMALTANK_H_
#include "Game.h"
#include "Item.h"
#include"Tank.h"
#include"EnemyTank.h"
#include<stdlib.h>
#include<ctime>

class NormalTank:public EnemyTank {
    int lastdx, lastdy;
    bool on;
public:
    NormalTank(Game* g) : EnemyTank(g){
        srand(time(0));
        int min_row = 5, max_row = 20;
        int min_col = 5, max_col = 70;
        int random_row = rand() % (max_row - min_row + 1) + min_row;
        int random_col = rand() % (max_col - min_col + 1) + min_col;
        row = random_row;
        col = random_row;
        dx = dy = lastdx = 0;
        lastdy = -1;
        health = 1;
        on = false;
    }
    void update(int key);
    void hit() {on = false;}
    bool died() { return on;}
    void reduceHealth();
    bool out();
};
#endif
