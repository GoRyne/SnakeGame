#pragma once
#include <stdlib.h>
#include <time.h>
#include "Map.h"
#include "Stage.h"

class Item {
    public:
        Item();
        ~Item();
        Stage Generate_item(Stage s);
};
