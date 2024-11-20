#pragma once

#include "Dacument/inc/dacument.h"
#include "Ui/CLI/cli.h"

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

}; 