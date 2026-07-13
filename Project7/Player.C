#include "Player.h"
#include "Game.h"
#include "Bullet.h"
#include <iostream>
using namespace std;

void Player::update(int key) {
    int shoot = 0;
    switch (key) {
    case KEY_LEFT:
        direction = -1;
        break;
    case KEY_RIGHT:
        direction = 1;
        break;
    case KEY_UP:
        location = -1;
        break;
    case KEY_DOWN:
        location = 1;
        break;
    case ' ':
        shoot = 1;
        break;
    default:
        direction = 0;
        location = 0;
        break;
    }
    if (shoot == 1 && game->getnumBullet() > 0) {
        //game->paintat(row, col, '0');
        game->addBullet(row, col);
        game->decreaseBullet();
    }
    //     game->paintat(row, col, ' ');
    col += direction;
    row += location;
    if (col > 65) { direction = 0; col = 65; }
    if (col < 5) { direction = 0; col = 5; }
    if (row > 24) { location = 0; row = 24; }
    if (row < 3) { location = 0; row = 3; }
    game->paintat(row, col, 'M');
}
bool Player::out() {
    if (col > 65 || col < 0) return true;
    else return false;
}
