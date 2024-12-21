#pragma once

#include "../Dacument/inc/Slide/slide.h"
#include "./ShapeFactory/shapefactory.h"

#include <memory>
#include <QPainter>
#include <QImage>


class Visualizer{
public:
    Visualizer();
    void printSlide(std::shared_ptr<Slide> slide);
    void printPage(std::shared_ptr<Page> page);

    void drowPage(std::shared_ptr<Page> page, std::string path);

private:

private:
    ShapeFactory shapeFactory;
    QPainter* painter;
    std::ostream& out;

};



