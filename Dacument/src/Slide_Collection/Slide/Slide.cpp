#include "Slide.h"

Slide::IteratorIthem Slide::ithemBegin()
{
    return ithems.begin();
}

Slide::IteratorIthem Slide::ithemEnd()
{
    return ithems.end();
}

Slide::constIteratorIthem Slide::cIthemBegin()
{
    return ithems.cbegin();
}


Slide::constIteratorIthem Slide::cIthemEnd()
{
    return ithems.end();
}