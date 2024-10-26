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

std::vector<std::shared_ptr<Page>>& Slide::getPages(Pos pos){
    return pages;  
}

size_t Slide::getPageCount()
{
    return pages.size();
}
