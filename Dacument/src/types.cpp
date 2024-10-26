#include "types.h"

sColor::sColor(char red, char green, char blue): red(red), green(green), blue(blue){
}

sGeometry& sGeometry::operator=(const sGeometry& other){
    if(this == (&other)){
        return;
    }
    this->x = other.x;
    this->y = other.y;
    this->len = other.len;
    this->hig = other.hig;
    return *this; 
}
