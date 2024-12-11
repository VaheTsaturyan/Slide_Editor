#pragma once

#include "types.h"
#include "page.h"

#include <list>    
#include <memory>


class Slide{  
public:
    using Iterator = std::list<std::shared_ptr<Page>>::iterator;
    using constIterator = std::list<std::shared_ptr<Page>>::const_iterator;

    Iterator begin();
    Iterator end();

    constIterator cBegin();
    constIterator cEnd();

    size_t getPageCount();
    std::shared_ptr<Page>& getPage(Pos ind);

    void pushBackPage(std::shared_ptr<Page> page);
    void popBackPage();
    void insertPage(Iterator it, std::shared_ptr<Page> page);
    void removePage(Iterator page);
    void swapPage(std::shared_ptr<Page> page1, std::shared_ptr<Page> page2);

private:
    std::list<std::shared_ptr<Page>> pages;
    
};
