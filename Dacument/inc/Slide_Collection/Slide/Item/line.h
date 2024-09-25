#pragma once
#include "interface.h"


class Line: public Item, public ItemVisual {
public:
    Line(ID id):Item(id){};
    
    pair<std::unordered_map<eKeysGeometry, Point>, std::unordered_map<eAttributes, Color>> reed() override;
    

    void construct(std::unordered_map<eKeysGeometry, Point> Geometry, std::unordered_map<eAttributes, Color> attribut) override;
    void modifyGeometry(std::unordered_map<eKeysGeometry, Point> Geometry) override;

private:
    Point startPoint;
    Point endPoint;
};