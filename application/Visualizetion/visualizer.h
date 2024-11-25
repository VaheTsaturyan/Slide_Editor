#pragma once

#include "../Dacument/inc/Slide/slide.h"

#include <memory>

class Visualizer{
public:
    static Visualizer& getVisualizer();
    void setSlide(std::shared_ptr<Slide> sld);
    void printSlide();
    void printPage(size_t ind);

private:
    Visualizer() = default;

private:
    std::shared_ptr<Slide> slide;

};

