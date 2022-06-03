#ifndef _MAP_
#define _MAP_
#include <ncurses.h>
#include "./Stage.h"
#include "item.h"
#include "gate.h"
#include "snake.h"
#include <clocale>
#include <locale.h>
using namespace std;

class Map {
    private:
    WINDOW *window_map, *window_mission, *window_score;
    int CurrentMap = 0;
    public:
        Map();
        ~Map();

        void UpdateMap();
        void InitScreen();
        void NextStage();
        void GetMission();
        int GetScore();
        int GetCurrentMap();
};

#endif _MAP_
