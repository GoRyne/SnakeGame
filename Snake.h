#pragma once

#include <vector>
#include "Position.h"

class Snake {
    public:
        Snake();
        ~Snake();

        char direction;
        int snakeLen;
        Position headPosition;
        std::vector<Position> bodies;

        void InitializeSnake();
        void Increase(Position P);
        void Decrease();
        void Move();
};
