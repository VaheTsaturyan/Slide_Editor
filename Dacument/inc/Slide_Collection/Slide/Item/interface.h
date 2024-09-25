#pragma once
#include "interface.h"

#include <functional>
#include <unordered_map>
#include <utility>

enum eKeysGeometry;
enum eAttributes;
struct  Point;
struct RGB;
struct ItemVisual;

using Color = char;
using Thickness = char;
using ID = const int;
using Position = Point;
 

class Item{
public:
    Item(int n):id(n){};

    virtual pair<std::unordered_map<eKeysGeometry, Point>, std::unordered_map<eAttributes, Color>> reed() = 0;
    
    virtual void construct(std::unordered_map<eKeysGeometry, Point> Geometry, std::unordered_map<eAttributes, Color> attribut) = 0;
    virtual void modifyGeometry(std::unordered_map<eKeysGeometry, Point> Geometry) = 0;
    virtual void modifyAttribut( std::unordered_map<eAttributes, Color> attribut);
    virtual void delet() = 0;
    virtual void setPosition(short x, short y);
    
    virtual ID getID();
    virtual Position getPosition();
    virtual ~Item() = 0;
protected:
    ItemVisual attributes;
    Position position;
    ID id;
};




enum eKeysGeometry{
    CENTER,
    RADIUS,
    START_POINT,
    END_POINT,
    HEIGHT,
    WIDHTH,
};

enum eAttributes{
    RED,
    GREEN,
    BLUE,
    LINE_THICKNESS
};

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


struct ItemVisual{
    RGB color;
    Thickness line_Thickness;
};








