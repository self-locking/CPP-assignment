#include <ncurses.h>
#include "Gui.h"
#include <cstring>
using namespace std;

void Gui::init() {
    initscr();                  /* Start curses mode              */
    refresh();                  /* Print it on to the real screen */
    win = stdscr;
    refresh();
    curs_set(0);                //隐藏光标，0表示不显示光标
    wrefresh(win);
    noecho();
    cbreak();
    keypad(win, true);
    nodelay(win, true);
    flushinp();
    for (int i = 1; i < 31; i++) {
        mvaddch(i, 1, '|');
        mvaddch(i, 80, '|');
    }
    for (int j = 2; j < 80; j++) {
        mvaddch(0, j, '-');
        mvaddch(31, j, '-');
    }
}

int Gui::get() {
    int c = wgetch(win);
    flushinp();
    return c;
}

void Gui::paintatBullet(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(1));
    wrefresh(win);
    return;
}
void Gui::paintatMine(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(5, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(5));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(5));
    wrefresh(win);
    return;
}
void Gui::paintatPlayer(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(2));
    wrefresh(win);
    return;
}
void Gui::paintatEnemy(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(3));
    wrefresh(win);
    return;
}
void Gui::paintatPack(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(4));
    wrefresh(win);
    return;
}
void Gui::paintatLaser(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(6));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(6));
    wrefresh(win);
    return;
}
void Gui::paintatObstacle(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(7));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(7));
    wrefresh(win);
    return;
}
void Gui::printMsg(int row, int col, const char* prompt, int v) {
    mvwprintw(win, row, col, prompt);
    char s[32];
    sprintf(s, "%d", v);        //将整数v转换为字符串，并存储在s中
    mvwprintw(win, row, col+strlen(prompt)+1, s);
}

void Gui::clear() {
    werase(win);                //清空指定窗口的内容，移除所有显示的字符
    for (int i = 1; i < 31; i++) {
        mvaddch(i, 1, '|');
        mvaddch(i, 80, '|');
    }
    for (int j = 2; j < 80; j++) {
        mvaddch(0, j, '-');
        mvaddch(31, j, '-');
    }
}

void Gui::redraw() {
    wrefresh(win);

}
