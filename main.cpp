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
    stage = item.Generate_item(stage);
    stage= map.UpdateMap(stage);


    while(true) {
        map.GetScore();
        map.GetMission();
        snake.setDirection();
        snake.Move();

        // 벽에 닿을 때.
        if (stage.stage[stage.Current_stage][snake.headPosition.GetPositionX()][snake.headPosition.GetPositionY()] == 1 || stage.stage[stage.Current_stage][snake.headPosition.GetPositionX()][snake.headPosition.GetPositionY()] == 2) {
            return 0;
        }

        // 몸에 닫을 때.
        std::vector<Position>::iterator it;
        for (it = snake.bodies.begin()+1; it != snake.bodies.end(); it++) {
            Position tmp = *it;
            if (snake.headPosition.GetPositionX() == tmp.GetPositionX() && snake.headPosition.GetPositionY() == tmp.GetPositionY()) {
                return 0;
            }
        }

        // 아이템에 닿을 때.
        if (stage.stage[stage.Current_stage][snake.headPosition.GetPositionX()][snake.headPosition.GetPositionY()] == 5) {
            snake.Increase(Position(snake.headPosition.GetPositionX(), snake.headPosition.GetPositionY()));
        } else if (stage.stage[stage.Current_stage][snake.headPosition.GetPositionX()][snake.headPosition.GetPositionY()] == 6) {
            snake.Decrease(stage);
            if (snake.snakeLen < 3) {
                return 0;
            }
        }

        stage = snake.MakeSnake(stage);
        map.UpdateMap(stage);
        usleep(500000);
    }

    return 0;
}
