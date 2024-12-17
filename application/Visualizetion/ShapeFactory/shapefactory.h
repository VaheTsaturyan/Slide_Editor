#pragma once

#include "../Shape/shape.h"

#include <unordered_map>
#include <memory>

class ShapeFactory{
public:
    void registrMap();
    std::shared_ptr<IShape> getShape(std::string type);

private:
    std::unordered_map<std::string, std::shared_ptr<IShape>> shapeMap;

};