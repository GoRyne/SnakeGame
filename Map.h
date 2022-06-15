#pragma once
#include <ncurses.h>
#include "Stage.h"
#include "Item.h"
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
        Stage NextStage(Stage s, Score *score, Snake *snake);
        void GetMission(Score s);
        int GetScore(Score s, Stage stage);
        int GetCurrentMap();
        void delScreen();
};
