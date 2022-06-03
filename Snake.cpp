#include <vector>
#include "Snake.h"

void Snake:: InitializeSnake () {
    headPosition = Position(4,3);
    bodies.push_back(headPosition);
    bodies.push_back(Position(4,2));
    bodies.push_back(Position(4,1));
}

void Snake:: Move () {
    if (direction == 'l') {
        headPosition = Position(headPosition.GetPositionX(), headPosition.GetPositionY()-1);
        bodies.insert(bodies.begin(), headPosition);
        bodies.pop_back();
    } else if (direction == 'r') {
        headPosition = Position(headPosition.GetPositionX(), headPosition.GetPositionY()+1);
        bodies.insert(bodies.begin(), headPosition);
        bodies.pop_back();
    } else if (direction == 'u') {
        headPosition = Position(headPosition.GetPositionX()-1, headPosition.GetPositionY());
        bodies.insert(bodies.begin(), headPosition);
        bodies.pop_back();
    } else if (direction == 'd') {
        headPosition = Position(headPosition.GetPositionX()+1, headPosition.GetPositionY());
        bodies.insert(bodies.begin(), headPosition);
        bodies.pop_back();
    }
}

void Snake:: Increase(Position P) {
    bodies.insert(bodies.begin(), P);
}

void Snake:: Decrease() {
    bodies.pop_back();
}