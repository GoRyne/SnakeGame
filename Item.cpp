#include "Item.h"
//성장아이템:5, 포이즌 아이템:6으로 설정

Stage Item:: Generate_item(Stage s){

    srand((unsigned)time(NULL));
    //매번 다른 난수 생성

    int cnt =0;
    int row, col;
    
    while(cnt < 2){
        row = rand() % 30;
        col = rand() % 40; 
        //col, row 랜덤좌표
        if(cnt == 0){
            s.stage[s.Current_stage][row][col] = 5; //성장아이템
            cnt++;
        }else{
            s.stage[s.Current_stage][row][col] = 6; //포이즌아이템
        }
    }
    return s;
}
