#include "Bomb.h"
#include "Game.h"
#include "Player.h"

void Bomb::update(int) {
    game->paintat(row, col, ' ');
    //if (row >= 11) return;
    row += 1;
    game->paintat(row, col, '0');
    Player* pl = game->getPlayer();
    /*if (col < pl->col) {
        row += 1;
        col += 1;
    }
    if (col > pl->col) {
        row += 1;
        col -= 1;
    }*/
    game->paintat(row, col, '0');
    if (row == pl->row && col == pl->col) game->gameend();
}

bool Bomb::out() {
    if (row >= 25) { 
        game->bombexist = 0; 
        return true;
    }
    else return false;
}
