#include <vector>
#include <ncurses.h>
#include "Snake.h"

void Snake:: InitializeSnake () {
    snakeLen = 3;
    bodies.push_back(headPosition);
    bodies.push_back(Position(4,2));
    bodies.push_back(Position(4,1));
}

Stage Snake:: MakeSnake(Stage s) {
    s.stage[s.Current_stage][tailPosition.GetPositionX()][tailPosition.GetPositionY()] = 0;

    std::vector<Position>::iterator it;
    for (it = bodies.begin(); it != bodies.end(); it++) {
        Position tmp = *it;
        
        if (it == bodies.begin()){
            s.stage[s.Current_stage][tmp.GetPositionX()][tmp.GetPositionY()] = 3;
        } else {
            s.stage[s.Current_stage][tmp.GetPositionX()][tmp.GetPositionY()] = 4;
        }
        tailPosition = tmp;
    }
    
    
    return s;
}

void Snake::setDirection()
{
    nodelay(stdscr, true);
    int key = getch();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    switch (key)
    {

    case KEY_RIGHT:
        direction = 'r'; // 우측 방향
        break;

    case KEY_LEFT:
        direction = 'l'; // 좌측 방향
        break;

    case KEY_UP:
        direction = 'u'; // 아래 방향
        break;

    case KEY_DOWN:
        direction = 'd'; // 위쪽 방향
        break;
    }
}

void Snake:: Move () {
    if (direction == 'l') {
        headPosition = Position(headPosition.GetPositionX(), headPosition.GetPositionY()-1);
        bodies.insert(bodies.begin(), headPosition);
        bodies.pop_back();
        headPosition = *bodies.begin();
    } else if (direction == 'r') {
        headPosition = Position(headPosition.GetPositionX(), headPosition.GetPositionY()+1);
        bodies.insert(bodies.begin(), headPosition);
        bodies.pop_back();
        headPosition = *bodies.begin();
    } else if (direction == 'u') {
        headPosition = Position(headPosition.GetPositionX()-1, headPosition.GetPositionY());
        bodies.insert(bodies.begin(), headPosition);
        bodies.pop_back();
        headPosition = *bodies.begin();
    } else if (direction == 'd') {
        headPosition = Position(headPosition.GetPositionX()+1, headPosition.GetPositionY());
        bodies.insert(bodies.begin(), headPosition);
        bodies.pop_back();
        headPosition = *bodies.begin();
    }
}

void Snake:: Increase(Position P) {
    snakeLen++;
    bodies.insert(bodies.begin(), P);
    headPosition = *bodies.begin();
}

void Snake:: Decrease(Stage s) {
    snakeLen--;
    Position tmp = *bodies.end();
    s.stage[s.Current_stage][tmp.GetPositionX()][tmp.GetPositionY()] = 0;
    bodies.pop_back();
}