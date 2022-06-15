#pragma once 
#include "Snake.h"
#include "Stage.h"
class Gate {
    public:
        Stage GenerateGate(Stage s);
        Stage Potal(Snake &snake, Stage &stage);
};
