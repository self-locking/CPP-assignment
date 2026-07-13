#include "Tank.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Tank::update(int k) {
    if (direction == true) col++;
    if (direction == false) col--;
    if (col == 5 || col == 65) direction = !direction;
    if (rand() % 100 < 9) game->addBomb(row, col);
    game->paintat(row, col - 1, 'C');
    game->paintat(row, col, 'M');
    game->paintat(row, col + 1, 'D');
}
bool Tank::out() {
    if (col < 4 || col > 66) {
        game->tankexist = 0; 
        return true;
    }
    if (game->bullethittank == true) {
        game->tankexist = 0;
        game->bullethittank = false;
        return true;
    }
    //if (game->gameover = true) return true;
	else return false;
}
void Tank::destroy() {
    disapper = true;
}
