#include "Tank.h"
#include "Game.h"
#include "Bullet.h"
#include <iostream>
#include <cstdlib>
#include"LaserTank.h"
using namespace std;

void LaserTank::update(int key) {
    updateCount++;
    if (updateCount < 100) {
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
        } 
        if (col >= MAXCOL) { col = MAXCOL - 1; dx = -1; }
        if (col <= 1) { col = 2; dx = 0; }
        if (row <= 1) { row = 2; dy = 0; }
        if (row >= MAXROW) { row = MAXROW - 1; dy = 0; }
        game->paintatLaser(row, col - 1, 'L');
        game->paintatLaser(row, col, 'A');
        game->paintatLaser(row, col + 1, 'S');
    }
    if (updateCount >= 100 && updateCount <= 102) {
        game->paintatLaser(row, col - 1, 'L');
        game->paintatLaser(row, col, 'A');
        game->paintatLaser(row, col + 1, 'S');
        if (lastdx == 1 && lastdy == 0) {
            for (int i = col + 2; i < MAXCOL; i++) {
                if (game->hitObstacle(row, i) == true) break;
                game->paintatLaser(row, i, 'X');
            }
            game->Laserhit(1, row, col);
        }
        else if (lastdx == -1 && lastdy == 0) {
            for (int i = col - 2; i > 1; i--) {
                if (game->hitObstacle(row, i) == true) break;
                game->paintatLaser(row, i, 'X');
            }
            game->Laserhit(2, row, col);
        }
        else if (lastdx == 0 && lastdy == 1) {
            for (int i = row + 1; i <= MAXROW; i++) {
                if (game->hitObstacle(row, i) == true) break;
                game->paintatLaser(i, col, 'X');
            }
            game->Laserhit(3, row, col);
        }
        else if (lastdx == 0 && lastdy == -1) {
            for (int i = row - 1; i >= 1; i--) {
                if (game->hitObstacle(row, i) == true) break;
                game->paintatLaser(i, col, 'X');
            }
            game->Laserhit(4, row, col);
        }
        else {}
        if (updateCount == 102) {
            updateCount = 0;
        }
    }
}
void LaserTank::reduceHealth() {
    health -= 1;
}
bool LaserTank::out() {
    if (health <= 0) {
        return true;
    }
    return false;
}

