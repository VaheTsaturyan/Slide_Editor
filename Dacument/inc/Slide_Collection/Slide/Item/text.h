#pragma once
#include "interface.h"

class Text : public Item, public ItemVisual{
    Text(ID id):Item(id){};
    Position position;
};

