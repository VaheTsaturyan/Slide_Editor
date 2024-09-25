#include "orthogonal.h"



pair<std::unordered_map<eKeysGeometry, Point>, std::unordered_map<eAttributes, Color>> Orthogonal::reed() override{

}


void Orthogonal::construct(std::unordered_map<eKeysGeometry, Point> Geometry, std::unordered_map<eAttributes, Color> attribut) override{
    modifyGeometry(Geometry);
    modifyAttribut(attribut);
}

void Orthogonal::modifyGeometry(std::unordered_map<eKeysGeometry, Point> Geometry) override{
    height = Geometry[eKeysGeometry::HEIGHT].x;
    width = Geometry[eKeysGeometry::WIDHTH].x;
}
