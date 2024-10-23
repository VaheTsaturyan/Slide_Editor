#include "slide.h"


Iterator Slide::begin()
{
    return pages.begin();
}


Iterator Slide::end()
{
    return pages.end();
}


constIterator Slide::cBegin()
{
    return pages.cbegin();
}


constIterator Slide::cEnd()
{
    return pages.cend();
}