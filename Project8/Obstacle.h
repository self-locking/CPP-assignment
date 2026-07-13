#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_
#include "Item.h"
class Game;


class Obstacle: public Item {
	Game* game;
public:
	Obstacle(Game* g,int r,int c) : game(g) {
		/*srand(time(0));
		int min_row = 5, max_row = 20;
		int min_col = 5, max_col = 70;
		int random_row = rand() % (max_row - min_row + 1) + min_row;
		int random_col = rand() % (max_col - min_col + 1) + min_col;
		row = random_row;
		col = random_col;*/
		row = r;
		col = c;
	}
	void update(int);
};


#endif
