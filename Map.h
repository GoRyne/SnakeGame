#ifndef _MAP_
#define _MAP_
#include <ncurses.h>
#include "./Stage.h"
#include "item.h"
#include "Gate.h"
#include "Snake.h"
#include <clocale>
#include <locale.h>
#include "Stage.h"
using namespace std;

class Map {
    private:
    WINDOW *window_map, *window_mission, *window_score;
    int CurrentMap = 0;
    public:

        Stage UpdateMap(Stage s);
        void InitScreen();
        void NextStage();
        void GetMission();
        int GetScore();
        int GetCurrentMap();
        void delScreen();
};

#endif _MAP_
