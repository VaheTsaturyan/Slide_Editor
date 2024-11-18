#pragma once

#include "types.h"
#include "page.h"

#include <vector>    
#include <memory>


class Slide{
public:

    using Iterator = std::vector<std::shared_ptr<Page>>::iterator;
    using constIterator = std::vector<std::shared_ptr<Page>>::const_iterator;
    
    void newSlide();

    Iterator begin();
    Iterator end();

    constIterator cBegin();
    constIterator cEnd();

    std::vector<std::shared_ptr<Page>>& getPages();
    size_t getPageCount();

private:

    std::vector<std::shared_ptr<Page>> pages;
};
