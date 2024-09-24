#pragma once
#include "interface.h"

using Center = Point;

class Circle : public Item, public ItemVisual{
    Circle(ID n):Item(n){};
    Position position;
    Center center;
    short radius;
};