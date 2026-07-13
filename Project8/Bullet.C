#include "Bullet.h"
#include "Game.h"
#include "Player.h"

void Bullet::update(int) {
    row += dy;
    col += dx;
    game->paintatBullet(row, col, '*');
}

bool Bullet::out() {
    if (row <= 0 || row >= 31 || col <= 1 || col >= 80 || game->Bullethit(row, col) == true || game->BullethitS(row, col) == true || game->Hit(row, col) == true || game->BullethitL(row, col) == true || game->hitObstacle(row, col) == true) return true;
    else return false;
}
