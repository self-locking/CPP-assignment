#ifndef _GAME_H_
#define _GAME_H_
#include <list>
#include "Gui.h"
#include <ctime>
#include <sys/time.h>
#include <ncurses.h>
using namespace std;
class Player;
class Bullet;
class Bomb;
class Tank;
class Coin;
class Item;
class Game {
    Gui gui;
    Player* pl;
    Tank* t1;
    Bomb* b1;
    Coin* c1;
    list <Item*> items;
    int numBullet;
    int score;
    time_t time1;
    int updateCounter;
public:
    Game();
    ~Game();
    void cleanup();
    int getnumBullet() { return numBullet; }
    void addBullet(size_t r, size_t c);
    void addBomb(size_t r, size_t c);
    void decreaseBullet();
    void addScore();
    void addTank(size_t r, size_t c);
    void addCoin(size_t r, size_t c);
    void Bullethit(Bullet* b, Tank* t);
    Tank* getTank();
    Player* getPlayer();
    void update();
    void paintat(size_t ro, size_t cl, char c) { gui.paintat(ro, cl, c); }
    void gameend();
    void reset();
    time_t currentTime;
    bool gameover;
    bool tankexist;
    bool bombexist;
    bool Bullethit(size_t row, size_t col);
    bool bullethittank;
    bool coinexist;
    bool getcoin(size_t row, size_t col);
};
#endif
