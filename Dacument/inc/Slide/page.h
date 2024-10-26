#pragma once 

#include "types.h"
#include "item.h"

#include <string>
#include <unordered_map>
#include <memory>


class Page{
public:
    using Iterator = std::unordered_map<ID, std::shared_ptr<AItem>>::iterator;  
    using constIterator = std::unordered_map<ID, std::shared_ptr<AItem>>::const_iterator;

    Iterator begin();
    Iterator end();

    constIterator cBegin();
    constIterator cEnd();

    void addIthem(std::shared_ptr<AItem> ithem);
    void removeIthem(ID id);

    std::shared_ptr<AItem> find(ID id);


private:
    std::unordered_map<ID, std::shared_ptr<AItem>> items;
};



/*





*/