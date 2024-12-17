#include "visualizer.h"

#include <iostream>
#include <iterator>



const int IMG_HIG = 600;
const int IMG_LEN = 800;

Visualizer::Visualizer():out(std::cout){
    shapeFactory.registrMap();
}

Visualizer &Visualizer::getVisualizer(){
    static Visualizer visualizer;
    return visualizer;
}


void Visualizer::printSlide(std::shared_ptr<Slide> slide){
    for(auto it = slide->cBegin(); it != slide->cEnd(); ++it){
        std::cout<<"page : "<<std::distance(slide->cBegin() , it)<<std::endl; 
        for(auto pIt = (*it)->cBegin(); pIt != (*it)->cEnd(); ++pIt){
            std::shared_ptr<IShape> shape = shapeFactory.getShape(pIt->second.getType());
            shape->print( out, pIt->second );
        }   
    }
}

void Visualizer::printPage(std::shared_ptr<Page> page){
    for(auto pIt = page->begin(); pIt != page->end(); ++pIt){
        std::shared_ptr<IShape> shape = shapeFactory.getShape(pIt->second.getType());
        shape->print( out, pIt->second );
    }   
}


void Visualizer::drowPage(std::shared_ptr<Page> page, std::string path){
    QImage* image = new QImage(IMG_LEN, IMG_HIG, QImage::Format_RGB16);
    image->fill(Qt::white);
    painter = new QPainter(image);
    for(auto it = page->cBegin(); it != page->cEnd(); ++it){
        std::shared_ptr<IShape> shape = shapeFactory.getShape(it->second.getType());
        shape->draw(painter, it->second );
    }
    QString qPath = QString::fromStdString(path);
    image->save(qPath);    
}
