#include "page.h"

#include <stdexcept>


Page::Iterator Page::begin()
{
    return items.begin();
}

Page::Iterator Page::end()
{
    return items.end();
}

Page::constIterator Page::cBegin()
{
    return items.cbegin();
}

Page::constIterator Page::cEnd()
{
    return items.cend();
}

void Page::addIthem(std::shared_ptr<AItem> ithem){
    items.emplace(ithem->getID(), ithem);
}


void Page::removeIthem(ID id)
{
    items.erase(id);
}

std::shared_ptr<AItem> Page::find(ID id){
    auto findResult = items.find(id);
    if(findResult == items.end()){
        throw std::runtime_error("CLI: No element with this ID found on this page\n");
    }
    return findResult->second;
}