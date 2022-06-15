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
    Score score;
    int count = -1;

    time_t current_time = 0;

    snake.InitializeSnake(); // 스네이크 초기화
    map.InitScreen(); //맵 초기화
    stage = item.Generate_item(stage);//stage에 item 추가
    stage = map.UpdateMap(stage); // stage를 map에 나타냄
    stage = gate.GenerateGate(stage); //stage에 gate 추가

    while(true) {
        map.GetScore(score, stage);
        map.GetMission(score);
        snake.setDirection();
        snake.Move();

        score.currentLength = snake.snakeLen;

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
        
        // 다음 스테이지로 넘어가야하는지 NextStage()를 통해서 확인.
        stage = map.NextStage(stage, &score, &snake);

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
            // 그로쓰 아이템 먹은 개수 확인.
            score.growthItem++;
            if (score.mission[stage.Current_stage][1] <= score.growthItem) {
                score.growthCheck = 1;
            }

            //스네이크 길이 증가.
            snake.Increase(Position(snake.headPosition.GetPositionX(), snake.headPosition.GetPositionY()));


        } else if (stage.stage[stage.Current_stage][snake.headPosition.GetPositionX()][snake.headPosition.GetPositionY()] == 6) {
            // 포이즌 아이템 먹은 개수 확인.
            score.poisonItem++;
            if (score.mission[stage.Current_stage][2] <= score.poisonItem) {
                score.poisonCheck = 1;
            }

            //스네이크 길이 감소.
            snake.Decrease(stage);
            if (snake.snakeLen < 3) {
                return 0;
            }
        }
        
        count--;

        // 게이트에 들어갈 때.
        if (stage.stage[stage.Current_stage][snake.headPosition.GetPositionX()][snake.headPosition.GetPositionY()] == 7) {
            // 미션 달성 조건 확인.
            score.gatePass++;
            if (score.mission[stage.Current_stage][3] <= score.gatePass) {
                score.gateCheck = 1;
            }
            // 게이트 통과 함수.
            stage = gate.Potal(&snake, stage);
            count = snake.bodies.size();
        }
        
        // 게이트 통과 후 원래 게이트가 있던 자리 초기화.
        if (count == 0) {
            stage.stage[stage.Current_stage][snake.gatePosition.GetPositionX()][snake.gatePosition.GetPositionY()] = 7;
        }
    
        stage = snake.MakeSnake(stage); //snake를 밑에 띄움
        map.UpdateMap(stage);
        usleep(300000);
    }

    return 0;
}
