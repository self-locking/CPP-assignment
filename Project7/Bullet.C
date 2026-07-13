#include "Bullet.h"
#include "Game.h"
#include "Tank.h"

void Bullet::update(int) {
    game->paintat(row, col, ' ');
    if (row <= 1) return;
    row--;
    game->paintat(row, col, '^');
    
    /*if (game->tankexist==true) {
        Tank* tank = game->getTank();
        if ((row == tank->row && col == tank->col - 1) ||
            (row == tank->row && col == tank->col) ||
            (row == tank->row && col == tank->col + 1)) {
            game->addScore();
            game->Bullethit(this, tank);
            return;
        }
    }*/
}

bool Bullet::out() {
    if (row <= 0 || game->Bullethit(row,col) == true) {
        return true;
    }
    else return false;
}
