#ifndef _SUPERTANK_H_
#define _SUPERTANK_H_
#include "Game.h"
#include "Item.h"
#include"Tank.h"
#include"EnemyTank.h"
#include<stdlib.h>
#include<ctime>

class SuperTank:public EnemyTank {
public:
    SuperTank(Game* g) : EnemyTank(g) {
        srand(time(0));
        int min_row = 5, max_row = 20;
        int min_col = 5, max_col = 70;
        int random_row = rand() % (max_row - min_row + 1) + min_row;
        int random_col = rand() % (max_col - min_col + 1) + min_col;
        row = random_row;
        col = random_col;
        dx = dy = 0;
        updateCount = 0;
        health = 5;
        t = 0;
    }
    int t;
    void update(int key);
    void reduceHealth();
    bool out();
};
#endif
