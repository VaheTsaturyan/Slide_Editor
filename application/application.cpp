#include "application.h"
#include <iostream>

Application::Application(){
    slide = std::make_shared<Slide>();
    controler = std::make_shared<Controler>();
    Loger::getLoger().addDivace(std::make_shared<OstreamDivace>(std::cout));
}

Application &Application::getAplication(){
    static Application aplication;
    return aplication;
}

int Application::exec(){
    controler->startProces();
    return 0;
}

std::shared_ptr<Slide> Application::getSlide(){
    return this->slide;
}

std::shared_ptr<Page> Application::getPage(){
    return this->page;
}

void Application::openPage(Pos pos){
    if(pos > slide->getPageCount()){
        throw std::runtime_error("CLI: Unable to add page with specified index");
    }
    this->page = *(std::next(slide->begin(), pos));
}

void Application::openSlide(std::shared_ptr<Slide> slide){
    this->slide = slide;
}
