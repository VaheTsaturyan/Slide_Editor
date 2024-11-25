#include "../inc/Slide/slide.h"


Slide::Iterator Slide::begin(){
    return pages.begin();
}


Slide::Iterator Slide::end()
{
    return pages.end();
}


Slide::constIterator Slide::cBegin()
{
    return pages.cbegin();
}


Slide::constIterator Slide::cEnd()
{
    return pages.cend();
}
/*

std::vector<std::shared_ptr<Page>>& Slide::getPages(){
    return pages;  
}

*/

size_t Slide::getPageCount(){
    return pages.size();
}


std::shared_ptr<Page>& Slide::getPage(Pos ind){
    return pages.at(ind);
}


#include <iostream>
void Slide::pushBackPage(){
    this->pages.emplace_back(std::make_shared<Page>());
    //std::cout<<this->pages.front()->i<<"bachwdkabdkjabwdj\n";
}

void Slide::popBackPage(){
    pages.pop_back();
}

void Slide::insertPage(Iterator it){
    pages.emplace(it, std::make_shared<Page>());
}

void Slide::removePage(Iterator it){
    pages.erase(it);
}

void Slide::swapPage(Pos pos1, Pos pos2){
    std::swap(pages[pos1], pages[pos2]);
}
