#include "Obstacle.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>

void Obstacle::update(int) {
	game->paintatObstacle(row, col, '#');
}

