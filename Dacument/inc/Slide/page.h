#pragma once 

#include "types.h"
#include "item.h"

#include <string>
#include <unordered_map> 
#include <memory>


class Page{
public:
    using Iterator = std::unordered_map<ID, std::shared_ptr<Item>>::iterator;  
    using constIterator = std::unordered_map<ID, std::shared_ptr<Item>>::const_iterator;

    Iterator begin();
    Iterator end();

    constIterator cBegin();
    constIterator cEnd();


private:
    std::unordered_map<ID, std::shared_ptr<Item>> items;
};



/*





*/