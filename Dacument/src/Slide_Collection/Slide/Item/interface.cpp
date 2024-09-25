#include "interface.h"


Item::~Item() {}

void Item::modifyAttribut(std::unordered_map<eAttributes, Color> attribut){
    attributes.color.red = attribut[eAttributes::RED];
    attributes.color.green = attribut[eAttributes::GREEN];
    attributes.color.bluu = attribut[eAttributes::BLUE];
    attributes.line_Thickness = attribut[eAttributes::LINE_THICKNESS];
    
    
}

void Item::setPosition(short x, short y){
    position.x = x;
    position.y = y;
}



ID Item::getID()
{
    return ID();
}

Position Item::getPosition()
{
    return Position();
}


