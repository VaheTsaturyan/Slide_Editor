#pragma once
#include "interface.h"


class Line: public Item, public ItemVisual {
public:
    Line(ID id):Item(id){};
    Position position;
    Point startPoint;
    Point endPoint;
};