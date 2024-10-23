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

    std::vector<std::shared_ptr<Page>>& getPages();

private:
    std::vector<std::shared_ptr<Page>> pages;
};

/*

    
    void addShape(Pos pos);
    void save();
    void RemoveShape(Pos pos);    
    void pushBackShape();
    void popBackShape();
    void pushFrontShape();
    void popFrontShape();
    void swapShape(Pos first, Pos second);
    void openShape(Pos pos);



*/