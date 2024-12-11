#pragma once 

#include "types.h"
#include "item.h"

#include <string>
#include <unordered_map>
#include <memory>


class Page{
public:
    using Iterator = std::unordered_map<ID, Ithem>::iterator;  
    using constIterator = std::unordered_map<ID, Ithem>::const_iterator;

    Iterator begin();
    Iterator end();

    constIterator cBegin();
    constIterator cEnd();

    void addIthem(Ithem& ithem);
    void removeIthem(ID id);

    Ithem& find(ID id);
    

private:
    std::unordered_map<ID, Ithem> items;

};



/*





*/