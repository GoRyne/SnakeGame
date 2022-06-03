#include "Gate.h"

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

void Potal(Snake s) {
    
}