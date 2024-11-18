#include "slideMeneger.h"

#include <stdexcept>

Slide SlideMeneger::slide;
Editor SlideMeneger::editor;
Sterializer SlideMeneger::sterializer;


void SlideMeneger::newSlide(){
    slide.newSlide();
}

void SlideMeneger::addPage(Pos pos)
{
    if(pos > slide.getPageCount()){
        std::runtime_error("CLI: Unable to add page with specified index");
    }
    auto sld = slide.getPages();
    auto it = sld.begin();
    for(int i = 0; i < pos; ++i){ ++it; }
    sld.emplace(it, std::make_shared<Page>());
}

void SlideMeneger::removePage(Pos pos){
    auto sld = slide.getPages();
    auto it = sld.begin();
    for(int i = 0; i < pos; ++i){ ++it; }
    sld.erase(it);
}

void SlideMeneger::swopPages(Pos first, Pos second){
    if(first > slide.getPageCount() || second > slide.getPageCount()){
        std::runtime_error("CLI: The specified pages or one of them does not exist");
    }
}

void SlideMeneger::openPage(Pos pos){
    if(pos > slide.getPageCount()){
        std::runtime_error("CLI: Unable to add page with specified index");
    }
    editor.setPage(slide.getPages()[pos]);
}

void SlideMeneger::addShape(std::string type, Pos x, Pos y, length len, length high){
    editor.addShape(type, x, y, len, high);
}

void SlideMeneger::moveVertical(ID id, Pos y){
    editor.moveVertical(id, y);
}

void SlideMeneger::moveHorizontal(ID id, Pos x){
    editor.moveHorizontal(id, x);
}

/*
void SlideMeneger::changeIthemColor(ID id, color::sColor color)
{
}

*/

void SlideMeneger::changeIthemLength(ID id, length len){
    editor.changeIthemLength(id, len);
}

void SlideMeneger::changeIthemHeight(ID id, length high){
    editor.changeIthemHeight(id, high);
}

void SlideMeneger::removeIthem(ID id){
    editor.removeIthem(id);
}
