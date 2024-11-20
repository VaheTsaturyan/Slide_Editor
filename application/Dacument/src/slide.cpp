#include "slide.h"

void Slide::newSlide(){
    this->pages.push_back(std::make_shared<Page>());
}

Slide::Iterator Slide::begin()
{
    return pages.begin();
}


Slide::Iterator Slide::end()
{
    return pages.end();
}


Slide::constIterator Slide::cBegin()
{
    return pages.cbegin();
}


Slide::constIterator Slide::cEnd()
{
    return pages.cend();
}

std::vector<std::shared_ptr<Page>>& Slide::getPages(){
    return pages;  
}

size_t Slide::getPageCount()
{
    return pages.size();
}
