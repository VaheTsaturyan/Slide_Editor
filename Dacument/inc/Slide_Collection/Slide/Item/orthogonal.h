#pragma once
#include "interface.h"


class Orthogonal : public Item , public ItemVisual
{
    Orthogonal(ID id):Item(id){};
    Position position;
    short height;
    short width;
};

