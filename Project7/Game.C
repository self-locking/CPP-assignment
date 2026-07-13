#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "Tank.h"
#include "Bomb.h"
#include"Coin.h"
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

Game::Game() {
    gui.init();
    pl = new Player(this);
    t1 = nullptr;
    b1 = nullptr;
    c1 = nullptr;
    srand(time(0));
    numBullet = 10;
    score = 0;
    gameover = false;
    updateCounter = 0;
    tankexist = 0;
    bombexist = 0;
    bullethittank = 0;
    coinexist = 0;
}
Game::~Game() {
    gui.end();
    cleanup();
}
void Game::addBullet(size_t r, size_t c) {
    items.push_back(new Bullet(this, r -1, c));
}
void Game::addBomb(size_t r, size_t c) {
    if (bombexist == 0) {
        b1 = new Bomb(this, r + 1, c);
        items.push_back(b1);
        bombexist = 1;
    }
}
void Game::addCoin(size_t r, size_t c) {
    if (coinexist == 0) {
        c1 = new Coin(this, r, c);
        items.push_back(c1);
        coinexist = 1;
    }
}
void Game::decreaseBullet() {
     numBullet--;
}
void Game::addScore() {
    score += 100;
}
void Game::addTank(size_t r, size_t c) {
    if (tankexist == 0) {
        t1 = new Tank(this, r, c);
        items.push_back(t1);
        tankexist = 1;
    }
}
Tank* Game::getTank() { return t1; }
Player* Game::getPlayer() { return pl; }

void Game::update() {
    if (gameover) {
        gui.printMsg(7, 28, "Game Over! Score: ", score);
        gui.printMsg(8, 28, "Press 'q' to quit", 0);
        usleep(3000000);
        int c = gui.get();
        if (c == 'q') {
            gui.end();
            exit(0);
        }
        else {
            reset();
        }
    }
    else {
        gui.clear();
        gui.printMsg(2, 68, "Bullet: ", numBullet);
        gui.printMsg(3, 68, "Score: ", score);
        int c = gui.get();
        if (rand() % 100 < 2) {
          if (rand() % 2 == 0) {addTank(2, 6);
          }
          else {
          addTank(2,64);
          }
        }

            if (rand() % 100 < 1) {
            int min_row = 4, max_row = 24;
            int min_col = 5, max_col = 65;
            srand(time(0));
            int random_row = rand() % (max_row - min_row + 1) + min_row;
            int random_col = rand() % (max_col - min_col + 1) + min_col;
            addCoin(random_row, random_col);
            }

        pl->update(c);
        if (numBullet < 10) updateCounter++;
        if (updateCounter >= 100 && numBullet < 10) {
            numBullet += 1;
            updateCounter = 0;
        }
        list<Item*>::iterator it = items.begin();
        while (it != items.end()) {
            (*it)->update(0);
            if ((*it)->out() == true) {
                delete* it;
                it = items.erase(it);
            }
            it++;
        }
    }
}
bool Game::Bullethit(size_t row,size_t col) {
    if (tankexist == 0) {return false;}
    if (t1->col-1 <= col && col <= t1->col + 1 && t1->row == row) {
        score += 100;
        bullethittank = 1;
        return true;
    }
    return false;
}
void Game::gameend() {
    gameover = true;
    /*gui.printMsg(7, 28, "Game Over! Score: ", score);
    gui.printMsg(8, 28, "Press 'q' to quit", 0);
    usleep(3000000);*/
    time1 = time(nullptr);
}
void Game::reset() {
    score = 0;
    numBullet = 10;
    gameover = false;
    bombexist = 0;
    tankexist = 0;
    for (Item* item : items) {
        delete item;
    }
    items.clear();
    //pl = new Player(this);
   /* if (t1) {
        delete tl;
        tl = nullptr;
    }*/
    srand(time(0));
    update();
}
void Game::cleanup() {
    for (Item* item : items) {
        delete item;
    }
    items.clear();
    /*if (t1) {
        delete t1;
        t1 = nullptr;
        tankexist = 0;
    }
    if (b1) {
        delete b1;
        b1 = nullptr;
        bombexist = 0;
    }*/
}


