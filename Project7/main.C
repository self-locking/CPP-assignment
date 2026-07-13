#include <ncurses.h>
#include "Gui.h"
#include <sys/time.h>
#include <chrono>
#include <thread>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <cstddef>
#include "Game.h"
using namespace std;


//int main()
//{
//
//    struct timeval time_now {};
//
//    gettimeofday(&time_now, NULL);
//    time_t oldTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
//    time_t currentTime = oldTime;
//    Game game;
//    while (true) {
//        gettimeofday(&time_now, NULL);
//        currentTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
//        if (currentTime - oldTime < 50) { usleep(25); continue; }
//        //usleep(100000);
//        game.update();
//        oldTime = currentTime;
//    }
//    return 0;
//}
int main() {
    using namespace std::chrono;

    // 获取当前系统时间点
    auto lastTime = steady_clock::now();
    auto frameDuration = milliseconds(16); // 约60FPS的目标时间间隔

    Game game;

    while (true) {
        auto currentTime = steady_clock::now();
        auto deltaTime = duration_cast<milliseconds>(currentTime - lastTime);

        if (deltaTime >= frameDuration) {
            game.update();
            lastTime = currentTime; // 更新最后一次更新的时间

            // 计算并确保不超过目标帧率的时间间隔
            auto sleepTime = frameDuration - deltaTime;
            if (sleepTime > milliseconds(0)) {
                std::this_thread::sleep_for(sleepTime);
            }
        }
        else {
            // 可选：让CPU稍作休息，避免占用过多CPU资源
            std::this_thread::sleep_for(milliseconds(1));
        }
    }

    return 0;
}
