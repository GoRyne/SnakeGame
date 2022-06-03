#include <iostream>
#include <ncurses.h>
#include "Map.h"
using namespace std;

int main() {
    Map map;
    Item item;
    Stage stage;
    
    map.InitScreen();
    stage = map.UpdateMap(stage);
}