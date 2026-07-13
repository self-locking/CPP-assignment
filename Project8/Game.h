#ifndef _GAME_H_
#define _GAME_H_
#include <list>
#include "Gui.h"
#include "Item.h"
using namespace std;
class RemovableItem;
class Player;
class Bullet;
class NormalTank;
class SuperTank;
class LaserTank;
class Obstacle;

class Game {
    Gui gui;
    Player* pl;
    NormalTank* normaltank;
    SuperTank* supertank;
    LaserTank* lasertank;
    Obstacle* obstacle;
    list <RemovableItem*> items;
    list <NormalTank*> normaltanks;
    list <SuperTank*> supertanks;
    list <LaserTank*> lasertanks;
    list <Obstacle*> obstacles;
    size_t score;
    int map[30][78];
public:
    int enemynumber;
    int tanks;
    int packnumber;
    int lasernumber;
    int obstaclenumber;
    int count;
    Game() ;
    ~Game() {gui.end();}
    void addRemovableItem(RemovableItem*);
    void addNormalTank(/*size_t row,size_t col*/);
    void addSuperTank();
    void addLaserTank();
    void addObstacle(int r,int c);
    bool hitObstacle(size_t row, size_t col);
    void update();
    void paintatMine(size_t ro, size_t cl, char c) {gui.paintatMine(ro, cl, c);}
    void paintatBullet(size_t ro, size_t cl, char c) { gui.paintatBullet(ro, cl, c); }
    void paintatPlayer(size_t ro, size_t cl, char c) { gui.paintatPlayer(ro, cl, c); }
    void paintatEnemy(size_t ro, size_t cl, char c) { gui.paintatEnemy(ro, cl, c); }
    void paintatPack(size_t ro, size_t cl, char c) { gui.paintatPack(ro, cl, c); }
    void paintatLaser(size_t ro, size_t cl, char c) { gui.paintatLaser(ro, cl, c); }
    void paintatObstacle(size_t ro, size_t cl, char c) { gui.paintatObstacle(ro, cl, c); }
    void updateRemovableItems() ;
    void updateTanks(int c);
    void updateObstacle();
    int trace();
    int minenumber;
    bool Bullethit(size_t row, size_t col);
    bool BullethitS(size_t row, size_t col);
    bool BullethitL(size_t row, size_t col);
    bool Hit(size_t row, size_t col);
    void Laserhit(int a, size_t row, size_t col);
    int enemytankstore;
    bool stepin(size_t row, size_t col);
    bool cure(size_t row, size_t col);
    void gameover();
    void reset();
    bool over;
    void printmap();
    void outputmap();
};
#endif
