#pragma once
#include "interface.h"

#include <functional>

using Color = char;
using Thickness = char;
using ID = const int;
using Position = Point;
 
struct  Point
{
    short x;
    short y;
};

struct RGB{
    Color red;
    Color green;
    Color bluu;
};



class Item{
public:
    Item(int n):id(n){};
    virtual void construct() = 0;
    virtual void reed(std::function<void()> reed) = 0;
    virtual void modify() = 0;
    virtual void delet() = 0;
    virtual ID getID() = 0;
    virtual ~Item() = 0;
private:
    ID id;
};

struct ItemVisual{
    RGB color;
    Thickness line_Thickness;
};