#include "Game.h"
#include "Player.h"
#include "EnemyTank.h"
#include "NormalTank.h"
#include "SuperTank.h"
#include "LaserTank.h"
#include "Bullet.h"
#include "Mine.h"
#include "Obstacle.h"
#include"MedicalPack.h"
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

Game::Game() {
    gui.init();
    pl = new Player(this);
    normaltank = nullptr;
    supertank = nullptr;
    lasertank = nullptr;
    score = 0;
    enemynumber = 20;
    enemytankstore = 20;
    tanks = 0;
    minenumber = 0;
    packnumber = 0;
    over = false;
    lasernumber = 0;
    obstaclenumber = 0;
    count = 0;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 78; j++) map[i][j] = 0;
    }
}

void Game::addRemovableItem(RemovableItem* rbi) {
    items.push_back(rbi);
}
void Game::addNormalTank(/*size_t row,size_t col*/) {
    normaltank = new NormalTank(this);
    normaltanks.push_back(normaltank);
}
void Game::addSuperTank() {
    supertank = new SuperTank(this);
    supertanks.push_back(supertank);
}
void Game::addLaserTank() {
    lasertank = new LaserTank(this);
    lasertanks.push_back(lasertank);
}
void Game::addObstacle(int r,int c) {
    obstacles.push_back(new Obstacle(this,r,c));
}
bool Game::Bullethit(size_t row, size_t col) {
    list<NormalTank*>::iterator bi = normaltanks.begin();
    for (bi = normaltanks.begin(); bi != normaltanks.end(); bi++){
        if (row == (*bi)->row && (col >= (*bi)->col - 1 && col <= (*bi)->col + 1)) {
                score += 50;
                NormalTank* tank = *bi;
                tank->reduceHealth();
                bi = normaltanks.erase(bi);
                normaltanks.push_front(tank);
                return true;
        } 
    }
    return false;
}
bool Game::BullethitS(size_t row, size_t col) {
    list<SuperTank*>::iterator si = supertanks.begin();
    for (si = supertanks.begin(); si != supertanks.end(); si++) {
        if (row == (*si)->row && (col >= (*si)->col - 1 && col <= (*si)->col + 1)) {
            SuperTank* stank = *si;
            stank->reduceHealth();
            si = supertanks.erase(si);
            supertanks.push_front(stank);
            return true;
        }
    }
    return false;
}
bool Game::BullethitL(size_t row, size_t col) {
    list<LaserTank*>::iterator li = lasertanks.begin();
    for (li = lasertanks.begin(); li != lasertanks.end(); li++) {
        if (row == (*li)->row && (col >= (*li)->col - 1 && col <= (*li)->col + 1)) {
            LaserTank* ltank = *li;
            ltank->reduceHealth();
            li = lasertanks.erase(li);
            lasertanks.push_front(ltank);
            return true;
        }
    }
    return false;
}
bool Game::Hit(size_t row, size_t col) {
    if (pl->row == row && pl->col == col) {
        pl->reduceHealth();
        return true;
    }
    return false;
}
void Game::Laserhit(int a, size_t row, size_t col) {
    list<NormalTank*>::iterator bi; /*= normaltanks.begin();*/
    list<SuperTank*>::iterator si;/* = supertanks.begin();*/
    switch (a) {
        case 1:
            if (pl->row == row && pl->col > col) pl->reduceHealth();
            for (bi = normaltanks.begin(); bi != normaltanks.end(); bi++) {
                if ((*bi)->row == row && (*bi)->col > col) {
                    NormalTank* tank = *bi;
                    tank->reduceHealth();
                    bi = normaltanks.erase(bi);
                    normaltanks.push_front(tank);
                }
            }
            for (si = supertanks.begin(); si != supertanks.end(); si++) {
                if ((*si)->row == row && (*si)->col > col) {
                    SuperTank* stank = *si;
                    stank->reduceHealth();
                    si = supertanks.erase(si);
                    supertanks.push_front(stank);
                }
            }
            break;
        case 2:
            if (pl->row == row && pl->col < col) pl->reduceHealth();
            for (bi = normaltanks.begin(); bi != normaltanks.end(); bi++) {
                if ((*bi)->row == row && (*bi)->col < col) {
                    NormalTank* tank = *bi;
                    tank->reduceHealth();
                    bi = normaltanks.erase(bi);
                    normaltanks.push_front(tank);
                }
            }
            for (si = supertanks.begin(); si != supertanks.end(); si++) {
                if ((*si)->row == row && (*si)->col < col) {
                    SuperTank* stank = *si;
                    stank->reduceHealth();
                    si = supertanks.erase(si);
                    supertanks.push_front(stank);
                }
            }
            break;
        case 3:
            if (pl->col == col && pl->row > row) pl->reduceHealth();
            for (bi = normaltanks.begin(); bi != normaltanks.end(); bi++) {
                if ((*bi)->col == col && (*bi)->row > row) {
                    NormalTank* tank = *bi;
                    tank->reduceHealth();
                    bi = normaltanks.erase(bi);
                    normaltanks.push_front(tank);
                }
            }
            for (si = supertanks.begin(); si != supertanks.end(); si++) {
                if ((*si)->col == col && (*si)->row > row) {
                    SuperTank* stank = *si;
                    stank->reduceHealth();
                    si = supertanks.erase(si);
                    supertanks.push_front(stank);
                }
            }
            break;
        case 4:
            if (pl->col == col && pl->row < row) pl->reduceHealth();
            for (bi = normaltanks.begin(); bi != normaltanks.end(); bi++) {
                if ((*bi)->col == col && (*bi)->row < row) {
                    NormalTank* tank = *bi;
                    tank->reduceHealth();
                    bi = normaltanks.erase(bi);
                    normaltanks.push_front(tank);
                }
            }
            for (si = supertanks.begin(); si != supertanks.end(); si++) {
                if ((*si)->col == col && (*si)->row < row) {
                    SuperTank* stank = *si;
                    stank->reduceHealth();
                    si = supertanks.erase(si);
                    supertanks.push_front(stank);
                }
            }
            break;
        default:
            break;
    }
}
bool Game::hitObstacle(size_t row, size_t col) {
    list<Obstacle*>::iterator oi;
    for (oi = obstacles.begin(); oi != obstacles.end(); oi++) {
        if (row == (*oi)->row && col == (*oi)->col) {
            return true;
        }
    }
    return false;
}


void Game::update() {
    while (obstaclenumber < 20) {
        int random_row = rand() % (30 - 1 + 1) + 1;
        int random_col = rand() % (80 - 1 + 1) + 1;
        addObstacle(random_row, random_col);
        map[random_row][random_col] = 1;
        obstaclenumber++;
    }
    printmap();
    if (count <= 100) {
        outputmap();
        count++;
        if (count == 100) gui.clear();
        gui.printMsg(32, 25, "The map you're on the way", 1);
    }
    else {
        gameover();
        if (over) {
            if (enemynumber == 0) {
                gui.clear();
                gui.printMsg(7, 28, "You're win! Score: ", score);
                gui.printMsg(8, 28, "Press 'q' to quit", 0);
                gui.redraw();
                usleep(3000000);
                int c = gui.get();
                if (c == 'q') {
                    gui.end();
                    exit(0);
                }
            }
            else {
                gui.clear();
                gui.printMsg(7, 28, "Game Over! Score: ", score);
                gui.printMsg(8, 28, "Press 'q' to quit", 0);
                gui.redraw();
                usleep(3000000);
                int c = gui.get();
                if (c == 'q') {
                    gui.end();
                    exit(0);
                }
            }
        }
        else {
            gui.clear(); //clear everything on the screen

            gui.printMsg(2, MAXCOL + 2, "Bullet", pl->reportNumBullet());
            gui.printMsg(3, MAXCOL + 2, "score: ", score);
            gui.printMsg(4, MAXCOL + 2, "HP: ", pl->reportHealth());
            gui.printMsg(5, MAXCOL + 2, "Enemynumber: ", enemynumber);

            if (rand() % 100 < 2 && tanks < 4 && enemytankstore > 0) {
                /*int min_row = 1, max_row = 29;
                int min_col = 1, max_col = 79;
                int random_row = rand() % (max_row - min_row + 1) + min_row;
                int random_col = rand() % (max_col - min_col + 1) + min_col;*/
                addNormalTank(/*random_row, random_col*/);
                tanks++;
                enemytankstore--;
            }
            if (rand() % 100 < 2 && tanks < 4 && enemytankstore > 0) {
                addSuperTank();
                tanks++;
                enemytankstore--;
            }
            if (rand() % 1000 < 1 && packnumber == 0) {
                int min_row = 2, max_row = 20;
                int min_col = 2, max_col = 70;
                int random_row = rand() % (max_row - min_row + 1) + min_row;
                int random_col = rand() % (max_col - min_col + 1) + min_col;
                addRemovableItem(new MedicalPack(this, random_row, random_col, 0, 0));
                packnumber++;
            }
            if (rand() % 100 < 1 && lasernumber < 2) {
                int min_row = 2, max_row = 20;
                int min_col = 2, max_col = 70;
                int random_row = rand() % (max_row - min_row + 1) + min_row;
                int random_col = rand() % (max_col - min_col + 1) + min_col;
                addLaserTank();
                lasernumber++;
            }
            /* while (obstaclenumber < 20) {
                 int random_row = rand() % (30 - 1 + 1) + 1;
                 int random_col = rand() % (80 - 1 + 1) + 1;
                 addObstacle(random_row,random_col);
                 obstaclenumber++;
             }*/
        }

        int c = gui.get();

        pl->update(c);

        updateRemovableItems();
        updateTanks(c);
        updateObstacle();

        gui.redraw(); //draw things

    }
}

void Game::updateTanks(int c) {
    list<NormalTank*>::iterator bi = normaltanks.begin();
    while (bi != normaltanks.end() ) {
        (*bi)->update(c);

        if ((*bi)->out() == true) {
           delete *bi;
           bi = normaltanks.erase(bi);
           enemynumber--;
           tanks--;
        }
        else ++bi;
    }
    list<SuperTank*>::iterator si = supertanks.begin();
    while (si != supertanks.end()) {
        (*si)->update(c);
        if ((*si)->out() == true) {
            delete* si;
            si = supertanks.erase(si);
            enemynumber--;
            tanks--;
            score += 100;
        }
        else si++;
    }
    list<LaserTank*>::iterator li = lasertanks.begin();
    while (li != lasertanks.end()) {
        (*li)->update(c);
        if ((*li)->out() == true) {
            delete* li;
            li = lasertanks.erase(li);
            lasernumber--;
            score += 50;
        }
        else li++;
    }
}

void Game::updateRemovableItems() {
    list<RemovableItem*>::iterator bi = items.begin();
    while (bi != items.end() ) {
        (*bi)->update(0);
        if ((*bi)->out() == true) {
           delete *bi;
           bi = items.erase(bi);
        }
        bi++;
    }
}
void Game::updateObstacle() {
    list<Obstacle*>::iterator oi = obstacles.begin();
    while (oi != obstacles.end()) {
        (*oi)->update(0);
        oi++;
    }
}
int Game::trace() {
    return pl->row * 100 + pl->col;
}
bool Game::stepin(size_t row, size_t col) {
    if ((pl->row >= row - 1 && pl->row <= row + 1) && (pl->col >= col - 1 && pl->col <= col + 1)) { 
        minenumber--;
        for (int i = 0; i < 5; i++) pl->reduceHealth();
        return true; 
    }
    else return false;
}
bool Game::cure(size_t row, size_t col) {
    if (pl->row == row && pl->col == col) {
        packnumber--;
        pl->cureHealth();
        return true;
    }
    return false;
}
void Game::gameover() {
    if (pl->reportHealth() <= 0) over = true;
    if (enemynumber == 0) over = true;
}
void Game::reset() {
    enemynumber = 20;
    enemytankstore = 20;
    tanks = 0;
    minenumber = 0;
    packnumber = 0;
    over = false;
    lasertank = 0;
   /* for (RemovableItem* item : items) {
        delete item;
    }
    items.clear();
    for (NormalTank* nt : normaltanks) {
        delete nt;
    }
    normaltanks.clear();
    for (SuperTank* st : supertanks) {
        delete st;
    }
    for (LaserTank* lt : lasertanks) {
        delete lt;
    }
    lasertanks.clear();*/
    items.clear();
    normaltanks.clear();
    supertanks.clear();
    lasertanks.clear();
    gui.clear();
    gui.redraw();
}
void Game::printmap() {
    ofstream outFile("map.txt");  // 打开文件进行写入

    if (outFile.is_open()) {
        // 遍历 obstacleMap，将其内容写入文件
        for (int r = 0; r < 30; ++r) {
            for (int c = 0; c < 78; ++c) {
                outFile << map[r][c];  // 输出位置的信息（0 或 1）
            }
            outFile << endl;  // 每行结束后换行
        }
        outFile.close();  // 关闭文件
    }
}
void Game::outputmap() {
    ifstream inFile("map.txt");  // 打开文件进行读取
    string line;
    int r = 0;

    if (inFile.is_open()) {
        // 读取并打印每一行到游戏屏幕
        while (getline(inFile, line) && r < 77) {
            for (int c = 0; c < MAXCOL && c < line.length(); ++c) {
                if (line[c] == '1') {
                    paintatObstacle(r, c , '#');  // 用 '#' 表示障碍物
                }
                else {
                    paintatObstacle(r , c, ' ');  // 用空格表示没有障碍物
                }
            }
            ++r;
        }
        inFile.close();  // 关闭文件
    }
}