#ifndef _MAP_
#define _MAP_

#include <ncurses.h>
#include "./Stage.h"

class Map {
    Map();
    ~Map();

    public:
        void UpdateMap();
        void GetCurrentMap();
        void GetScore();
        void GetMission();
        
};

#endif _MAP_