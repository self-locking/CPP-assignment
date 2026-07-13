#include "Coin.h"
#include "Game.h"
#include"Player.h"

void Coin::update(int) {
	game->paintat(row, col, '*');
}
bool Coin::out() {
	Player* pl = game->getPlayer();
	if (row == pl->row && col == pl->col) {
		game->addScore();
		game->coinexist = 0;
		return true;
	}
	return false;
}
