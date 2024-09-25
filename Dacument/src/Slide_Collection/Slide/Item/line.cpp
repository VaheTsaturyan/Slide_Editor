#include "line.h"



pair<std::unordered_map<eKeysGeometry, Point>, std::unordered_map<eAttributes, Color>> Line::reed() override{

}


void Line::construct(std::unordered_map<eKeysGeometry, Point> Geometry, std::unordered_map<eAttributes, Color> attribut) override{
    modifyGeometry(Geometry);
    modifyAttribut(attribut);
}

void Line::modifyGeometry(std::unordered_map<eKeysGeometry, Point> Geometry) override{
    startPoint =  Geometry[eKeysGeometry::START_POINT];
    endPoint = Geometry[eKeysGeometry::END_POINT];
}
