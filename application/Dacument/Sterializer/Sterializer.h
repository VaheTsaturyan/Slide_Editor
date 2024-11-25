#pragma once

#include "../inc/Slide/slide.h"


class Sterializer{
public:
    static Sterializer& getSterilizer();
private:
    Sterializer() = default;

};