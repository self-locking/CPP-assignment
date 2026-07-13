#ifndef _ITEM_H_
#define _ITEM_H_
#include "Game.h"

class Item {
public:
	size_t row;
	size_t col;
	Game* game;
	Item(Game* g, size_t r, size_t c) : game(g), row(r), col(c) {}
	~Item();
	virtual void update(int);
	virtual bool out();
};
#endif
