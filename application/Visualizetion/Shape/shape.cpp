#include "shape.h"

#include <string>

void AShape::setPen(QPainter *painter, const sAtributs &atributs){
    auto colorPen = atributs.map.find(std::string("colorpen"));
    if(colorPen == atributs.map.end()){
        painter->setPen(QPen(Qt::black));
    }else{
        int red = static_cast<int>(colorPen->second[0]);
        int green = static_cast<int>(colorPen->second[1]);
        int blue = static_cast<int>(colorPen->second[2]);
        QColor color(red, green, blue);
        painter->setPen(QPen(color));
    }
}

void AShape::setBrash(QPainter *painter, const sAtributs &atributs){
    auto colorFill = atributs.map.find(std::string("colorfill"));
    if(colorFill == atributs.map.end()){
        painter->setBrush(QBrush(Qt::white));
    }else{
        int red = static_cast<int>(colorFill->second[0]);
        int green = static_cast<int>(colorFill->second[1]);
        int blue = static_cast<int>(colorFill->second[2]);
        QColor color(red, green, blue);
        painter->setBrush(QBrush(color));
    }
}


void RectangleShape::draw(QPainter *painter, const Ithem &ithem){
    const sAtributs& atributs = ithem.getAtributs();
    const sGeometry&  geometry = ithem.getGeometry();
    setPen(painter, atributs);
    setBrash(painter, atributs);
    painter->drawRect(geometry.x, geometry.y, geometry.len, geometry.hig);
}

void RectangleShape::print(std::ostream &out, const Ithem &ithem){
    const sAtributs& atributs = ithem.getAtributs();
    const sGeometry&  geometry = ithem.getGeometry();
    std::string type = atributs.map.at("type");
    out<<"id: "<<ithem.getID()<<" type: "<< type <<" x: "<< geometry.x<<" y: "<< geometry.y<< " len: "<< geometry.len<< " hig: "<< geometry.hig <<std::endl;
}

std::shared_ptr<IShape> RectangleShape::copy(){
    return std::make_shared<RectangleShape>();
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ElipsShape::draw(QPainter *painter, const Ithem &ithem){
    const sAtributs& atributs = ithem.getAtributs();
    const sGeometry&  geometry = ithem.getGeometry();
    setPen(painter, atributs);
    setBrash(painter, atributs);
    painter->drawEllipse(geometry.x, geometry.y, geometry.len, geometry.hig);
}

void ElipsShape::print(std::ostream &out, const Ithem &ithem){
    const sAtributs& atributs = ithem.getAtributs();
    const sGeometry&  geometry = ithem.getGeometry();
    std::string type = atributs.map.at("type");
    out<<"id: "<< ithem.getID()<<" type: "<< type <<" x: "<< geometry.x<<" y: "<< geometry.y<< " len: "<< geometry.len<< " hig: "<< geometry.hig <<std::endl;
}

std::shared_ptr<IShape> ElipsShape::copy(){
    return std::make_shared<ElipsShape>();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LineShape::draw(QPainter *painter, const Ithem &ithem){
    const sAtributs& atributs = ithem.getAtributs();
    const sGeometry&  geometry = ithem.getGeometry();
    setPen(painter, atributs);
    setBrash(painter, atributs);
    painter->drawLine(geometry.x, geometry.y, geometry.len, geometry.hig);
}

void LineShape::print(std::ostream &out, const Ithem &ithem){
    const sAtributs& atributs = ithem.getAtributs();
    const sGeometry&  geometry = ithem.getGeometry();
    std::string type = atributs.map.at("type");
    out<<"id: "<< ithem.getID()<<" type: "<< type <<" x: "<< geometry.x<<" y: "<< geometry.y<< " len: "<< geometry.len<< " hig: "<< geometry.hig <<std::endl;
}

std::shared_ptr<IShape> LineShape::copy(){
    return std::make_shared<LineShape>();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TextShape::draw(QPainter *painter, const Ithem &ithem){
    const sAtributs& atributs = ithem.getAtributs();
    const sGeometry&  geometry = ithem.getGeometry();
    setPen(painter, atributs);
    setBrash(painter, atributs);
    QString text = QString::fromStdString(atributs.map.at("text"));
    painter->drawText(geometry.x, geometry.y, text);
}

void TextShape::print(std::ostream &out, const Ithem &ithem){
    const sAtributs& atributs = ithem.getAtributs();
    const sGeometry&  geometry = ithem.getGeometry();
    std::string type = atributs.map.at("type");
    std::string text = atributs.map.at("text");
    out<<"id: "<< ithem.getID()<<" type: "<< type <<" x: "<< geometry.x<<" y: "<< geometry.y<<" text: "<< text <<std::endl;
}

std::shared_ptr<IShape> TextShape::copy(){
    return std::make_shared<TextShape>();
}
