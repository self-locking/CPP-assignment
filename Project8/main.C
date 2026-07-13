#include <ncurses.h>
#include "Gui.h"
#include <sys/time.h>
#include<stdlib.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <cstddef>
#include "Game.h"
using namespace std;


int main()
{
    srand(time(0));
    struct timeval time_now {};

    gettimeofday(&time_now, NULL);
    time_t oldTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    time_t currentTime =  oldTime;
    Game game;
    while (true) {
        gettimeofday(&time_now, NULL);
        currentTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
        if (currentTime - oldTime < 50) {usleep(1);continue;}
        //usleep(1000000);
        game.update();
        oldTime = currentTime;
    }
    return 0;
}
