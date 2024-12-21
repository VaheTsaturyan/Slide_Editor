#include "shapefactory.h"
#include <stdexcept>

void ShapeFactory::registrMap(){
    shapeMap.emplace(std::string("rectangle"), std::make_shared<RectangleShape>());
    shapeMap.emplace(std::string("elips"), std::make_shared<ElipsShape>());
    shapeMap.emplace(std::string("line"), std::make_shared<LineShape>());
}

std::shared_ptr<IShape> ShapeFactory::getShape(std::string type){
    auto el = shapeMap.find(type);
    if(el == shapeMap.end()){
        throw std::runtime_error("shape not found\n");
    }
    return el->second->copy();

}