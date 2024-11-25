#include "../inc/Slide/item.h"


AItem::AItem(ID id):id_(id){
}

AItem::AItem(const AItem &other):id_(other.id_){
    this->geometry_ = other.geometry_;
    this->atributs_ = other.atributs_;
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
