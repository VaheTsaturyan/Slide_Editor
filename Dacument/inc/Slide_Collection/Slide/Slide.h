#pragma once
#include <list>

#include "./Item/circle.h"
#include "./Item/line.h"
#include "./Item/orthogonal.h"
#include "./Item/text.h"

class Slide
{
public:
    using IteratorOrthogonal = std::list<Orthogonal*>::iterator;
    using IteratorCircle = std::list<Circle*>::iterator;
    using IteratorLines = std::list<Line*>::iterator;
    using IteratorTexts = std::list<Text*>::iterator;

    
    using constIteratorOrthogonal = std::list<Orthogonal*>::const_iterator;
    using constIteratorCircle = std::list<Circle*>::const_iterator;
    using constIteratorLines = std::list<Line*>::const_iterator;
    using constIteratorTexts = std::list<Text*>::const_iterator;

    IteratorOrthogonal beginOrthogonal();
    IteratorOrthogonal endOrthogonal();
    IteratorCircle beginCircle();
    IteratorCircle endCircle();
    IteratorLines begoinLines();
    IteratorLines endLines(); 
    IteratorTexts beginText();
    IteratorTexts endText();

    constIteratorOrthogonal cBeginOrthogonal();
    constIteratorOrthogonal cEndOrthogonal();
    constIteratorCircle cBeginCircle();
    constIteratorCircle cEndCircle();
    constIteratorLines cBegoinLines();
    constIteratorLines cEndLines(); 
    constIteratorTexts cBeginText();
    constIteratorTexts cBndText();



private:
    std::list<Orthogonal*> orthogonals;
    std::list<Circle*> circls;
    std::list<Line*> lines;
    std::list<Text*> texts;
};
