#include "Tank.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include "EnemyTank.h"
using namespace std;

//EnemyTank::EnemyTank(Game* g) {
//    game = g;
//    if (rand() % 2 == 0) {
//        dx = 1;
//        dy = 0;
//        col = 1;
//    }
//    else {
//        dx = -1;
//        dy = 0;
//        col = MAXCOL - 1;
//    }
//   
//    health = 100;    
//    updateCount = 0;
//}

//void EnemyTank::update(int key) /*{
//     col += dx;
//     row += dy;
//     if (col > MAXCOL) {col = MAXCOL; dx = -1;}
//     if (col <1) {col = 1; dx = 1;}
//     game->paintat(row, col, 'O');
//}*/

void EnemyTank::reduceHealth() {
    return;
}
//bool EnemyTank::isHit(int r, int c, int range) /*{
//    if (row == r + range || row == r - range) {
//        if (col == c + range || col == c - range) return true;
//    }
//    return false;
//}*/

bool EnemyTank::out() {return false;}
