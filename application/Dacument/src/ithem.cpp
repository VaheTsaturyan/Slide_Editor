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

void AItem::setAtributs(sAtributs&& atributs){
    atributs_ = std::move(atributs);
}

sAtributs &AItem::getAtributs(){
    return atributs_;
}
