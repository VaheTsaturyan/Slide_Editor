#include "ithem.h"
#include "item.h"

AItem::Atem(ID id):id_(id){
}


void AItem::setGeometry(const sGeometry &geometry){
    geometry_ = geometry;
}

sGeometry& AItem::getGeometry() const{
    return geometry_;
}

id AItem::getID() const{
    return this->id_;
}
