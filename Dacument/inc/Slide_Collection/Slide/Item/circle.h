#pragma once
#include "interface.h"

using Center = Point;

class Circle : public Item, public ItemVisual{
public:
    Circle(ID n):Item(n){};
    
    
    pair<std::unordered_map<eKeysGeometry, Point>, std::unordered_map<eAttributes, Color>> reed() override;
    

    void construct(std::unordered_map<eKeysGeometry, Point> Geometry, std::unordered_map<eAttributes, Color> attribut) override;
    void modifyGeometry(std::unordered_map<eKeysGeometry, Point> Geometry) override;


private:
    Center center;
    short radius;
};