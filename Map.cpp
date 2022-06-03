#include "Map.h"

    Map();
    ~Map();

    void Map:: InitScreen(){
        
        initscr();// initscr(): ncurses TUI 모드 시작
        start_color(); // start_color(): 색깔 사용
        setlocale(LC_ALL, "");// 유니코드 사용
        curs_set(0);// 커서 안보이게함
        noecho();// 키보드 입력한 값을 화면에 안보이게함

       
        window_map = newwin(30, 40, 15, 15); // @window_map: x = 15, y = 15 위치에 가로 40, 세로 30의 크기의 윈도우
        window_mission = newwin(10, 30, 5, 15); // @window_mission: 미션 표시 윈도우
        window_score = newwin(10, 30, 5, 55); // @window_score: 점수 표시 윈도우

    };
    void UpdateMap();
    
    void NextStage();
    void GetMission();
    int GetScore();


    int GetCurrentMap() {
    
}
