#include "MedicalPack.h"
#include "Game.h"

void MedicalPack::update(int) {
	game->paintatPack(row, col, '+');
}
bool MedicalPack::out() {
	if (game->cure(row, col) == true) {
		return true;
	}
	return false;
}



