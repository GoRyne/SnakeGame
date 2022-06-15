#include "Gate.h"
#include "Map.h"

Stage Gate:: GenerateGate(Stage s) {

    srand((unsigned)time(NULL));
    //매번 다른 난수 생성

    int cnt =0;
    int row, col;
    
    while(cnt < 2){
        row = (rand() % 29);
        col = (rand() % 39);
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

Stage Gate:: Potal(Snake *snake, Stage stage) {
    Position input_gate = snake->headPosition;
    Position output_gate = Position(0,0);
    snake->gatePosition = input_gate;
    Map map;
    
    char direct;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 40; j++) {
            if (stage.stage[stage.Current_stage][i][j] == 7 && snake->headPosition.GetPositionX() != i && snake->headPosition.GetPositionY() != j) {
                output_gate = Position(i,j);
            }
        }
    }
    
    // 스네이크의 포탈 이동을 위해 방향 설정. 

    if (snake->direction == 'u') {
        if (stage.stage[stage.Current_stage][output_gate.GetPositionX()-1][output_gate.GetPositionY()] == 0) {
            direct = 'u';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()+1] == 0) {
            direct = 'r';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()-1] == 0) {
            direct = 'l';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()+1][output_gate.GetPositionY()] == 0) {
            direct = 'd';
        }
    } else if (snake->direction == 'l') {
        if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()-1] == 0) {
            direct = 'l';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()-1][output_gate.GetPositionY()] == 0) {
            direct = 'u';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()+1][output_gate.GetPositionY()] == 0) {
            direct = 'd';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()+1] == 0) {
            direct = 'r';
        }
    } else if (snake->direction == 'd') {
        if (stage.stage[stage.Current_stage][output_gate.GetPositionX()+1][output_gate.GetPositionY()] == 0) {
            direct = 'd';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()-1] == 0) {
            direct = 'l';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()+1] == 0) {
            direct = 'r';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()-1][output_gate.GetPositionY()] == 0) {
            direct = 'u';
        }
    } else if (snake->direction == 'r') {
        if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()+1] == 0) {
            direct = 'r';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()+1][output_gate.GetPositionY()] == 0) {
            direct = 'd';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()-1][output_gate.GetPositionY()] == 0) {
            direct = 'u';
        } else if (stage.stage[stage.Current_stage][output_gate.GetPositionX()][output_gate.GetPositionY()-1] == 0) {
            direct = 'l';
        }
    }
    

    // 뱀의 머리가 게이트에 닿았을 때 반대쪽 게이트로 머리가 나오도록 설정  
    // 게이트 통과도 게임 클리어 조건이기 때문에 뱀의 길이가 늘어남(원하지 않으면 snake->bodies.pop_back()을 해주면 됨).

    if (direct == 'u') {
        snake->bodies.insert(snake->bodies.begin() ,Position(output_gate.GetPositionX()-1, output_gate.GetPositionY()));
        snake->headPosition = Position(output_gate.GetPositionX()-1, output_gate.GetPositionY());

    } else if (direct == 'd') {
        snake->bodies.insert(snake->bodies.begin(), Position(output_gate.GetPositionX()+1, output_gate.GetPositionY()));
        snake->headPosition = Position(output_gate.GetPositionX()+1, output_gate.GetPositionY());

    } else if (direct == 'l') {
        snake->bodies.insert(snake->bodies.begin(), Position(output_gate.GetPositionX(), output_gate.GetPositionY()-1));
        snake->headPosition = Position(output_gate.GetPositionX(), output_gate.GetPositionY()-1);

    } else if (direct == 'r') {
        snake->bodies.insert(snake->bodies.begin(), Position(output_gate.GetPositionX(), output_gate.GetPositionY()+1));
        snake->headPosition = Position(output_gate.GetPositionX(), output_gate.GetPositionY()+1);

    }

    snake->direction = direct;
    
    return stage;
}