#pragma once

#include "../Dacument/inc/Slide/slide.h"

#include <memory>

class Visualizer{
public:
    static Visualizer& getVisualizer();
    void printSlide(std::shared_ptr<Slide> slide);
    void printPage(std::shared_ptr<Page> page);

private:
    Visualizer() = default;


};

