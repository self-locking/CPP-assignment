#ifndef _GUI_H_
#define _GUI_H_
#include <ncurses.h>

class Gui {
    size_t row;
    size_t col;
    WINDOW* win;
public:
    Gui ():row(20),col(50) {init();}
    ~Gui() {endwin();}
    void init();
    int get();
    void paintatMine(size_t, size_t, char);
    void paintatBullet(size_t, size_t, char);
    void paintatPlayer(size_t, size_t, char);
    void paintatEnemy(size_t, size_t, char);
    void paintatPack(size_t, size_t, char);
    void paintatLaser(size_t, size_t, char);
    void paintatObstacle(size_t, size_t, char);
    void printMsg(int row, int col, const char* prompt, int v);
    void clear();
    void redraw();
    void end() {endwin();}
};
#endif
