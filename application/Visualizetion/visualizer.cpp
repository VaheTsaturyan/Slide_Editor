#include "visualizer.h"

#include <iostream>
#include <iterator>

Visualizer &Visualizer::getVisualizer(){
    static Visualizer visualizer;
    return visualizer;
}


void Visualizer::printSlide(std::shared_ptr<Slide> slide){
    for(auto it = slide->begin(); it != slide->end(); ++it){
        std::cout<<"page : "<<std::distance(slide->begin() , it)<<std::endl; 
        for(auto pIt = (*it)->begin(); pIt != (*it)->end(); ++pIt){
            auto geometry = pIt->second.getGeometry();
            auto atributs = pIt->second.getAtributs();
            std::string type = atributs.map["type"];
            std::cout<<"\tid: "<<pIt->first<<" type: "<< type <<" x: "<< geometry.x<<" y: "<< geometry.y<< " len: "<< geometry.len<< " hig: "<< geometry.hig <<std::endl;
        }   
    }
}

void Visualizer::printPage(std::shared_ptr<Page> page){
        for(auto pIt = page->begin(); pIt != page->end(); ++pIt){
            auto geometry = pIt->second.getGeometry();
            auto atributs = pIt->second.getAtributs();
            std::string type = atributs.map["type"];
            std::cout<<"id: "<<pIt->first<<"type: "<< type <<" x: "<< geometry.x<<" y: "<< geometry.y<< " len: "<< geometry.len<< " hig: "<< geometry.hig <<std::endl;
        }   
}

