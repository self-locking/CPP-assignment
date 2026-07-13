#include "Mine.h"
#include "Game.h"
#include "SuperTank.h"

void Mine::update(int) {
    game->paintatMine(row, col, '!');
}

bool Mine::out() {
    if (game->stepin(row , col) == true) return true;
    else return false;
}
