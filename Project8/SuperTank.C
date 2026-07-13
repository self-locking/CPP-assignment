#include "Tank.h"
#include "Game.h"
#include "Bullet.h"
#include <iostream>
#include <cstdlib>
#include"SuperTank.h"
#include"Mine.h"
using namespace std;

void SuperTank::update(int key) {
    updateCount++;
    t++;
    if (updateCount == 10) {
        if (rand() % 2 == 1) {
            if (col < game->trace() % 100) {
                col++;
                if (game->hitObstacle(row, col) == true || game->hitObstacle(row, col - 1) == true || game->hitObstacle(row, col + 1) == true) col--;
            }
            if (col > game->trace() % 100) {
                col--;
                if (game->hitObstacle(row, col) == true || game->hitObstacle(row, col - 1) == true || game->hitObstacle(row, col + 1) == true) col++;
            }
        }
        else {
            if (row < game->trace() / 100) {
                row++;
                if (game->hitObstacle(row, col) == true || game->hitObstacle(row, col - 1) == true || game->hitObstacle(row, col + 1) == true) row--;
            }
            if (row > game->trace() / 100) {
                row--;
                if (game->hitObstacle(row, col) == true || game->hitObstacle(row, col - 1) == true || game->hitObstacle(row, col + 1) == true) row++;
            }
        }
        updateCount = 0;
    }

    if (col >= MAXCOL) { col = MAXCOL; dx = -1; }
    if (col <= 1) { col = 1; dx = 0; }
    if (row <= 1) { row = 1; dy = 0; }
    if (row >= MAXROW) { row = MAXROW; dy = 0; }
    game->paintatEnemy(row, col - 1, 'C');
    game->paintatEnemy(row, col, 'N');
    game->paintatEnemy(row, col + 1, 'D');
    if (/*rand() % 100 == 5*/t == 100 && game->minenumber < 10) {
        game->addRemovableItem(new Mine(game, row, col, dx, dy));
        game->minenumber++;
        t = 0;
    }
}
void SuperTank::reduceHealth() {
    health -= 1;
}
bool SuperTank::out() {
    if (health <= 0) return true;
    return false;
}
