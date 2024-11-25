#include "application.h"
#include <iostream>

Application::Application(){
    slide = std::make_shared<Slide>();
    controler = std::make_shared<Controler>();
    editor = std::make_shared<Editor>();
    sterializer = std::make_shared<Sterializer>();
    this->visualizer = std::make_shared<Visualizer>();
}

int Application::exec(){
    editor->setSlide(slide);
    visualizer->setSlide(slide);
    //controler->setIstream(std::cin);
    controler->setEditor(editor);
    controler->setSterilizer(sterializer);
    controler->setVisualizer(visualizer);
    controler->startProces();
    return 0;
}