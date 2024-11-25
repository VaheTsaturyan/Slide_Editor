#pragma once

#include "types.h"
#include "page.h"

#include <vector>    
#include <memory>


class Slide{  
public:
    using Iterator = std::vector<std::shared_ptr<Page>>::iterator;
    using constIterator = std::vector<std::shared_ptr<Page>>::const_iterator;

    Iterator begin();
    Iterator end();

    constIterator cBegin();
    constIterator cEnd();

    size_t getPageCount();
    std::shared_ptr<Page>& getPage(Pos ind);

    void pushBackPage();
    void popBackPage();
    void insertPage(Iterator page);
    void removePage(Iterator page);
    void swapPage(Pos pos1, Pos pos2);

private:
    std::vector<std::shared_ptr<Page>> pages;
    
    //std::list<std::shared_ptr<Page>>& getPages();
    
};
