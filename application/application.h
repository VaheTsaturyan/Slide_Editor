#pragma once

#include "Dacument/inc/dacument.h"
#include "./UI/CLI/cli.h"
#include "./Visualizetion/visualizer.h"
#include "./Logger/inc/logger.h"

#include <memory>

class Application{
public:
    static Application& getAplication();    
    int exec();
    std::shared_ptr<Slide> getSlide();
    std::shared_ptr<Page> getPage();

    void openPage(Pos pos);

    void openSlide(std::shared_ptr<Slide> slide);
private:    
    Application();
    Application(const Application&) = delete;
    Application(Application&&) = delete;
    Application& operator=(const Application&) = delete;
    Application& operator=(Application&&) = delete;

private:
    std::shared_ptr<Slide> slide;
    std::shared_ptr<Page> page;
    std::shared_ptr<Controler> controler;
}; 