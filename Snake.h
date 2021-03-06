#pragma once

#include <vector>
#include "Position.h"
#include "Stage.h"

class Snake {
    public:
        char direction;
        int snakeLen;
        Position headPosition = Position(4,3);
        Position tailPosition = Position(4,1);
        Position gatePosition = Position(0,0);
        std::vector<Position> bodies;

        void setDirection();
        void InitializeSnake();
        void Increase(Position P);
        void Decrease(Stage s);
        void Move();
        Stage MakeSnake(Stage s);
};
