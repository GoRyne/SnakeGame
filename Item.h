#ifndef _ITEM_
#define _ITEM_
#pragma once
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "stage.h"

class Item {
    public:
        Item();
        ~Item();
        void Generate_item();
};

#endif _ITEM_