#pragma once
#include <list>

#include "./Item/circle.h"
#include "./Item/line.h"
#include "./Item/orthogonal.h"
#include "./Item/text.h"

class Slide
{
public:
    using IteratorIthem = std::list<Item*>::iterator;
    using constIteratorIthem = std::list<Item*>::const_iterator;

    IteratorIthem ithemBegin();
    IteratorIthem ithemEnd();

    constIteratorIthem cIthemBegin();
    constIteratorIthem cIthemEnd();

private:
    std::list<Item*> ithems;
};
