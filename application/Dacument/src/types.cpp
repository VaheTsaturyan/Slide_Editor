#include "../inc/Slide/types.h"


color::sColor::sColor(unsigned char red, unsigned char green, unsigned char blue): red(red), green(green), blue(blue){
}

sGeometry::sGeometry(Pos x_, Pos y_, length len_, length hig_):x(x_), y(y_), len(len_), hig(hig_){
}

sGeometry::sGeometry(const sGeometry &other){
    this->x = other.x;
    this->y = other.y;
    this->len = other.len;
    this->hig = other.hig;
}
sGeometry::sGeometry(sGeometry &&other){    
    this->x = other.x;
    this->y = other.y;
    this->len = other.len;
    this->hig = other.hig;
}
sGeometry &sGeometry::operator=(const sGeometry &other){
    if(this == (&other)){
        return *this;
    }
    this->x = other.x;
    this->y = other.y;
    this->len = other.len;
    this->hig = other.hig;
    return *this;
}

sGeometry &sGeometry::operator=(sGeometry &&other){   
    if(this == (&other)){
        return *this;
    }
    this->x = other.x;
    this->y = other.y;
    this->len = other.len;
    this->hig = other.hig;
    return *this;
}

sAtributs::sAtributs(sAtributs &&other){
    this->map = std::move(other.map);
}

sAtributs::sAtributs(const sAtributs &other){
    this->map = other.map;
}

sAtributs &sAtributs::operator=(sAtributs &&other)
{
    if(this == &other){
        return *this;
    }
    this->map = std::move(other.map);
    return *this;
}

sAtributs &sAtributs::operator=(const sAtributs &other)
{
    if(this == &other){
        return *this;
    }
    this->map = other.map;
    return *this;

}
