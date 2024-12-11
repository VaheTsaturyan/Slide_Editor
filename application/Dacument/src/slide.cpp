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
    
    return *(std::next(pages.begin(), ind));
}


#include <iostream>
void Slide::pushBackPage(std::shared_ptr<Page> page){
    this->pages.push_back(page);
    //std::cout<<this->pages.front()->i<<"bachwdkabdkjabwdj\n";
}

void Slide::popBackPage(){
    pages.pop_back();
}

void Slide::insertPage(Iterator it, std::shared_ptr<Page> page){
    pages.insert(it, page);
}

void Slide::removePage(Iterator it){
    pages.erase(it);
}

void Slide::swapPage(std::shared_ptr<Page> page1, std::shared_ptr<Page> page2){
    std::swap(page1, page2);
}
