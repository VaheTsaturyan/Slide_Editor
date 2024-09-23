#include "Slide_Collection.h"

Slide_Collection::Iterator Slide_Collection::begin()
{
    return slides.begin();
}

Slide_Collection::Iterator Slide_Collection::end()
{
    return slides.end();
}

Slide_Collection::constIterator Slide_Collection::cBegin()
{
    return slides.cbegin();
}

Slide_Collection::constIterator Slide_Collection::cEnd()
{
    return slides.cend();
}
 