#include "../inc/Slide/item.h"


Ithem::Ithem(ID id):id_(id){
}

Ithem::Ithem(const Ithem &other):id_(other.id_){
    this->geometry_ = other.geometry_;
    this->atributs_ = other.atributs_;
}

void Ithem::setGeometry(const sGeometry &geometry){
    geometry_ = geometry;
}

sGeometry& Ithem::getGeometry(){
    return geometry_;
}

ID Ithem::getID() const{
    return this->id_;
}

void Ithem::setAtributs(sAtributs&& atributs){
    atributs_ = std::move(atributs);
}


sAtributs &Ithem::getAtributs(){
    return atributs_;
}

std::string &Ithem::getType(){
    return atributs_.map[std::string("type")];
}
