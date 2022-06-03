#pragma once
#include <ncurses.h>
#include "Stage.h"
// #include "Item.h"
// #include "Gate.h"
// #include "Snake.h"
#include <clocale>
#include <locale.h>
using namespace std;

class Map {
    private:
    WINDOW *window_map, *window_mission, *window_score;
    int CurrentMap = 0;
    public:
        void UpdateMap();
        void InitScreen();
        void NextStage();
        void GetMission();
        int GetScore();
        int GetCurrentMap();
};

