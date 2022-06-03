#include "Item.h"
//성장아이템:5, 포이즌 아이템:6으로 설정

Stage Item:: Generate_item(Stage s){

    srand((unsigned)time(NULL));
    //매번 다른 난수 생성

    int cnt =0;
    int row, col;
    
    while(cnt < 2){
        row = (rand() % 29) + 1;
        col = (rand() % 39) + 1;
        //col, row 랜덤좌표

        if(s.stage[s.Current_stage][row][col] != 0){
            continue;
        }else{
            if(cnt == 0){
                s.stage[s.Current_stage][row][col] = 5; //성장아이템
                cnt++;
            }else{
                s.stage[s.Current_stage][row][col] = 6;
                cnt++; //포이즌아이템
        }       
        }
    }
    return s;
}

Stage Item:: Delete_item(Stage s) {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 40; j++) {
            if (s.stage[s.Current_stage][i][j] == 6 || s.stage[s.Current_stage][i][j] == 5) {
                s.stage[s.Current_stage][i][j] = 0;
            }
        }
    }
    return s;
}