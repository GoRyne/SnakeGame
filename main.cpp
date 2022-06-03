#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Map.h"
using namespace std;

int main() {
    Map map;
    Item item;
    Stage stage;
    Snake snake;

    snake.InitializeSnake(); // 스네이크 초기화
    map.InitScreen(); //맵 초기화
    stage = item.Generate_item(stage); //아이템 생성
    stage= map.UpdateMap(stage);


    while(true) {
        
        snake.setDirection();
        snake.Move();
        stage = snake.MakeSnake(stage);
        map.UpdateMap(stage);

        // 벽에 닿을 때.
        if (snake.headPosition.GetPositionX() > 29 || snake.headPosition.GetPositionX() < 0 || snake.headPosition.GetPositionY() > 39 || snake.headPosition.GetPositionY() < 0 ) {

        }

        // 몸에 닫을 때.
        std::vector<Position>::iterator it;
        for (it = snake.bodies.begin(); it != snake.bodies.end(); it++) {

        }

        // 아이템에 닿을 때.
        if (stage.stage[stage.Current_stage][snake.headPosition.GetPositionX()][snake.headPosition.GetPositionY()] == 5) {
            snake.Increase(Position(snake.headPosition.GetPositionX(), snake.headPosition.GetPositionY()));
        } else if (stage.stage[stage.Current_stage][snake.headPosition.GetPositionX()][snake.headPosition.GetPositionY()] == 6) {
            snake.Decrease();
        }


        usleep(100000);
    }

    return 0;
}
