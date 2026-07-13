#include "Player.h"
#include "Game.h"
#include "Item.h"
#include "Bullet.h"
#include <iostream>
using namespace std;

//Player::Player(Game* g) {
//    game = g;
//    row = 20;
//    col = 25;
//    dx = 0;
//    dy = 0;
//    updateCount = 0;
//    numBullet = 20;
//    health = 100;
//    lastdx = 0;
//    lastdy = -1;
//}
void Player::update(int key) {
     int shoot = 0;
     updateCount++;
     if (updateCount > MAXCOUNT) {
         numBullet++;
         if (numBullet > MAXNUMBULLET) numBullet = MAXNUMBULLET;
         updateCount = 0;
     }
     switch (key) {
         case KEY_LEFT:
             dx = -1;
             lastdx = -1;
             lastdy = 0;
             col += dx;
             if (game->hitObstacle(row, col) == true) col -= dx;
             break;
         case KEY_RIGHT:
             dx = 1;
             lastdx = 1;
             lastdy = 0;
             col += dx;
             if (game->hitObstacle(row, col) == true) col -= dx;
             break;
         case KEY_UP:
             dy = -1;
             lastdx = 0;
             lastdy = -1;
             row += dy;
             if (game->hitObstacle(row, col) == true) row -= dy;
             break;
         case KEY_DOWN:
             dy = 1;
             lastdx = 0;
             lastdy = 1;
             row += dy;
             if (game->hitObstacle(row, col) == true) row -= dy;
             break;
         case ' ':
             shoot = 1;
             break;
         default:
             dx = 0;
             dy = 0;
             break;
     }
     if (shoot == 1 && numBullet > 0) {
             game->addRemovableItem(new Bullet(game, row, col, lastdx, lastdy/* this*/));
             numBullet--;
     }
     if (col >= MAXCOL - 1) { dx = 0; col = MAXCOL - 1; }
     if (col < 2) { dx = 0; col = 2; }
     if (row >= MAXROW) { dy = 0; row = MAXROW;}
     if (row <= 1) { dy = 0; row = 1; }
     game->paintatPlayer(row, col, 'M');
}

bool Player::out() {return false;}


void Player::reduceHealth() {
   health -= 1;
}
void Player::cureHealth() {
    health = 10;
}

