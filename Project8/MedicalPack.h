#ifndef _MEDICALPACK_H_
#define _MEDICALPACK_H_
#include "RemovableItem.h"
#include "Game.h"
#include "Item.h"

class MedicalPack : public RemovableItem {
public:
	MedicalPack(Game* g, size_t r, size_t c, int dx1, int dy1) : RemovableItem(g, r, c, dx1, dy1) {}
	void update(int);
	bool out();
};
#endif
