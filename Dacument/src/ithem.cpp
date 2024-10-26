#include "item.h"

AItem::AItem(ID id):id_(id){
}


void AItem::setGeometry(const sGeometry &geometry){
    geometry_ = geometry;
}

sGeometry& AItem::getGeometry(){
    return geometry_;
}

ID AItem::getID() const{
    return this->id_;
}


Rectangle::Rectangle(ID id): AItem(id){
}