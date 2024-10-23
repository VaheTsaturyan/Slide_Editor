#include "page.h"

Iterator Page::begin()
{
    return items.begin();
}

Iterator Page::end()
{
    return items.end();
}

constIterator Page::cBegin()
{
    return items.cbegin();
}

constIterator Page::cEnd()
{
    return items.cend();
}