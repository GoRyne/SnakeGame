#include "Gate.h"
#include "Map.h"

Stage Gate:: GenerateGate(Stage s) {

    srand((unsigned)time(NULL));
    //매번 다른 난수 생성

    int cnt =0;
    int row, col;
    
    while(cnt < 2){
        row = (rand() % 29) + 1;
        col = (rand() % 39) + 1;
        //col, row 랜덤좌표

        if(s.stage[s.Current_stage][row][col] != 1){
            continue;
        }else{
            s.stage[s.Current_stage][row][col] = 7; 
            cnt++;
        }
    }
    return s;

}

Stage Gate:: Potal(Snake &snake, Stage &stage) {
    Position input_gate = snake.headPosition;
    Position output_gate = Position(0,0);
    std::vector<Position> output;

    char direct;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 40; j++) {
            if (stage.stage[stage.Current_stage][i][j] == 7 && snake.headPosition.GetPositionX() != i && snake.headPosition.GetPositionY() != j) {
                output_gate = Position(i,j);
            }
        }
    }

    if (snake.direction == 'u') {
        if (stage.stage[stage.Current_stage][output_gate.GetPositionX()-1][output_gate.GetPositionY()]) {
            direct = 'u';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()+1]) {
            direct = 'r';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()-1]) {
            direct = 'l';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()+1][output_gate.GetPositionY()]) {
            direct = 'd';
        }
    } else if (snake.direction == 'l') {
        if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()-1]) {
            direct = 'l';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()-1][output_gate.GetPositionY()]) {
            direct = 'u';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()+1][output_gate.GetPositionY()]) {
            direct = 'd';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()+1]) {
            direct = 'r';
        }
    } else if (snake.direction == 'd') {
        if (stage.stage[stage.Current_stage][output_gate.GetPositionX()+1][output_gate.GetPositionY()]) {
            direct = 'd';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()-1]) {
            direct = 'l';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()+1]) {
            direct = 'r';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()-1][output_gate.GetPositionY()]) {
            direct = 'u';
        }
    } else if (snake.direction == 'r') {
        if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()+1]) {
            direct = 'r';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()+1][output_gate.GetPositionY()]) {
            direct = 'd';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()-1][output_gate.GetPositionY()]) {
            direct = 'u';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()-1]) {
            direct = 'l';
        }
    }


    for (int i = 0; i < snake.bodies.size(); i++) {
        if (direct == 'u') {
            output.push_back(Position(output_gate.GetPositionX()-1, output_gate.GetPositionY()));
            snake.bodies.erase(snake.bodies.begin());
            snake.headPosition = *snake.bodies.begin();

        } else if (direct == 'd') {
            output.push_back(Position(output_gate.GetPositionX()+1, output_gate.GetPositionY()));
            snake.bodies.erase(snake.bodies.begin());
            snake.headPosition = *snake.bodies.begin();

        } else if (direct == 'l') {
            output.push_back(Position(output_gate.GetPositionX(), output_gate.GetPositionY()-1));
            snake.bodies.erase(snake.bodies.begin());
            snake.headPosition = *snake.bodies.begin();

        } else if (direct == 'r') {
            output.push_back(Position(output_gate.GetPositionX(), output_gate.GetPositionY()+1));
            snake.bodies.erase(snake.bodies.begin());
            snake.headPosition = *snake.bodies.begin();

        }
    }

    return stage;
}