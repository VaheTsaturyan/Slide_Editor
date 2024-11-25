#pragma once

#include "Dacument/inc/dacument.h"
#include "./UI/CLI/cli.h"
#include "./Visualizetion/visualizer.h"

#include <memory>

class Application{
public:
    Application();
    int exec();
    
private:
    std::shared_ptr<Slide> slide;
    std::shared_ptr<Controler> controler;
    std::shared_ptr<Editor> editor;
    std::shared_ptr<Sterializer> sterializer;
    std::shared_ptr<Visualizer> visualizer;

}; 