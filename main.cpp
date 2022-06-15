#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Map.h"
#include "Gate.h"
using namespace std;

int main() {
    Map map;
    Item item;
    Stage stage;
    Snake snake;
    Gate gate;

    time_t current_time = 0;

    snake.InitializeSnake(); // 스네이크 초기화
    map.InitScreen(); //맵 초기화
    stage = item.Generate_item(stage);//stage에 item 추가
    stage = map.UpdateMap(stage); // stage를 map에 나타냄
    stage = gate.GenerateGate(stage); //stage에 gate 추가

    while(true) {
        map.GetScore();
        map.GetMission();
        snake.setDirection();
        snake.Move();

        // 랜덤으로 아이템이 생성되는 것.
        if (current_time == 0) {
            current_time = time(NULL);
        } else {
            if (time(NULL) - current_time > rand() % 100) {
                current_time = 0;
                stage = item.Delete_item(stage);
                stage = item.Generate_item(stage);
            }
        }
        

        //snake가 move시 제약 조건
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

        // 게이트에 들어갈 때.
        if (stage.stage[stage.Current_stage][snake.headPosition.GetPositionX()][snake.headPosition.GetPositionY()] == 7) {
            stage = gate.Potal(snake, stage);
        }

        stage = snake.MakeSnake(stage); //snake를 밑에 띄움
        map.UpdateMap(stage);
        usleep(200000);
    }

    return 0;
}
