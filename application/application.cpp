#include "application.h"
#include <iostream>

Application::Application(){
    slide = std::make_shared<Slide>();
    controler = std::make_shared<Controler>();

}

int Application::exec(){
    Editor::getEditor().setSlide(slide);
    Visualizer::getVisualizer().setSlide(slide);
    controler->startProces();
    return 0;
}