#include "visualizer.h"

#include <iostream>
#include <iterator>

Visualizer &Visualizer::getVisualizer(){
    static Visualizer visualizer;
    return visualizer;
}

void Visualizer::setSlide(std::shared_ptr<Slide> sld)
{
    this->slide = sld;
}

void Visualizer::printSlide(){
    for(auto it = slide->begin(); it != slide->end(); ++it){
        std::cout<<"page : "<<std::distance(slide->begin() , it)<<std::endl; 
        for(auto pIt = (*it)->begin(); pIt != (*it)->end(); ++pIt){
            auto geometry = pIt->second.getGeometry();
            std::cout<<"id: "<<pIt->first<<" x: "<< geometry.x<<" y: "<< geometry.y<< " len: "<< geometry.len<< " hig: "<< geometry.hig <<std::endl;
        }   
    }
}

void Visualizer::printPage(size_t ind){
   auto it = slide->begin();
   std::advance(it, ind);
        std::cout<<"page : "<<ind<<std::endl; 
        for(auto pIt = (*it)->begin(); pIt != (*it)->end(); ++pIt){
            auto geometry = pIt->second.getGeometry();
            std::cout<<"id: "<<pIt->first<<" x: "<< geometry.x<<" y: "<< geometry.y<< " len: "<< geometry.len<< " hig: "<< geometry.hig <<std::endl;
        }   
}

