#include "Tank.h"
#include "Game.h"
#include "Bullet.h"
#include <iostream>
#include <cstdlib>
#include"NormalTank.h"
using namespace std;

void NormalTank::update(int key) {
    int n = rand() % 100;
    if (n < 5) {  
        dx = 1; dy = 0;
        lastdx = 1; lastdy = 0;
        col += dx;
        if (game->hitObstacle(row, col) == true || game->hitObstacle(row, col - 1) == true || game->hitObstacle(row, col + 1) == true) col -= dx;
    }
    else if (n < 10) {  
        dx = -1; dy = 0;
        lastdx = -1; lastdy = 0;
        col += dx;
        if (game->hitObstacle(row, col) == true || game->hitObstacle(row, col - 1) == true || game->hitObstacle(row, col + 1) == true) col -= dx;
    }
    else if (n < 15) { 
        dx = 0; dy = 1;
        lastdx = 0; lastdy = 1;
        row += dy;
        if (game->hitObstacle(row, col) == true || game->hitObstacle(row, col - 1) == true || game->hitObstacle(row, col + 1) == true) row -= dy;
    }
    else if (n < 20) { 
        dx = 0; dy = -1;
        lastdx = 0; lastdy = -1;
        row += dy;
        if (game->hitObstacle(row, col) == true || game->hitObstacle(row, col - 1) == true || game->hitObstacle(row, col + 1) == true) row -= dy;
    }
    else {
        dx = 0; dy = 0;
        if (n < 30) {
            if (lastdx == 1) {
                game->addRemovableItem(new Bullet(game, row, col + 2, lastdx, lastdy/* this*/));
            }
            if (lastdx == -1) {
                game->addRemovableItem(new Bullet(game, row, col - 2, lastdx, lastdy/* this*/));
            }
            if (lastdy == 1) {
                game->addRemovableItem(new Bullet(game, row + 1, col, lastdx, lastdy/* this*/));
            }
            if (lastdy == -1) {
                game->addRemovableItem(new Bullet(game, row - 1, col, lastdx, lastdy/* this*/));
            }
        }
    }

    updateCount = 0;
    if (col >=MAXCOL) { col = MAXCOL -1; dx = -1; }
    if (col <= 1) { col = 2; dx = 0; }
    if (row <= 1) { row = 2; dy = 0; }
    if(row >=MAXROW) { row = MAXROW - 1; dy = 0;}
     game->paintatEnemy(row, col-1, 'c');
     game->paintatEnemy(row, col, 'n');
     game->paintatEnemy(row, col+1, 'd');
}
void NormalTank::reduceHealth() {
    health -= 1;
}
bool NormalTank::out() {
    if (health <= 0) {
        return true;
    }
    return false;
}