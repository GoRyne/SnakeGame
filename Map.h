#ifndef _MAP_
#define _MAP_
#include <ncurses.h>
#include "./Stage.h"

class Map {
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