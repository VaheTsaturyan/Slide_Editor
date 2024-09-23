#pragma once
#include <list>

#include "./Slide/Slide.h"

class Slide_Collection
{
    using Iterator = std::list<Slide*>::iterator;
    using constIterator = std::list<Slide*>::const_iterator; 

    Iterator begin();
    Iterator end();
    constIterator cBegin();
    constIterator cEnd();

private:

    std::list<Slide*> slides;

};
