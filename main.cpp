#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Map.h"
using namespace std;

int main() {
    Map map;
    Item item;
    Stage stage;
    
    map.InitScreen(); //맵 초기화

    stage = item.Generate_item(stage); //아이템 생성

    stage= map.UpdateMap(stage);

    map.UpdateMap(stage);
    map.GetMission();
    map.GetScore();
    stage = map.UpdateMap(stage);
    map.GetScore();
    map.GetMission();


    return 0;
}
