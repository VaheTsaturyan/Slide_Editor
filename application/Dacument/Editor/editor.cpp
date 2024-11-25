#include "editor.h"

#include <stdexcept>
#include <iostream>

Editor &Editor::getEditor(){
    static Editor editor;
    return editor;

}

void Editor::setSlide(std::shared_ptr<Slide> slide)
{
    this->slide_ = slide;
}

void Editor::newSlide()
{
    slide_->pushBackPage();
}

void Editor::addPage(Pos pos)
{
    if(pos > slide_->getPageCount()){
        std::runtime_error("CLI: Unable to add page with specified index");
    }
    auto it = slide_->begin();
    for(size_t i = 0; i < pos; ++i){ ++it; }
    slide_->insertPage(it);
}

void Editor::pushBackPage(){
    slide_->pushBackPage();
}

void Editor::popBackPage(){
    slide_->popBackPage();
}

void Editor::removePage(Pos pos){
    auto it = slide_->begin();
    for(size_t i = 0; i < pos; ++i){ ++it; }
    slide_->removePage(it);
}



void Editor::swapPages(Pos first, Pos second)
{
    if(first > slide_->getPageCount() || second > slide_->getPageCount()){
        std::runtime_error("CLI: The specified pages or one of them does not exist");
    }
    slide_->swapPage(first, second);
}

void Editor::openPage(Pos pos)
{
    if(pos > slide_->getPageCount()){
        std::runtime_error("CLI: Unable to add page with specified index");
    }
    setPage(slide_->getPage(pos));
}

void Editor::addShape(std::string type, const std::unordered_map<std::string, int>& paramsMap){
    AItem ithem = AItem(genereytId());
    sAtributs temp;
    temp.map.emplace(atr::Type, type);
    temp.map.emplace(atr::Color, "0.0.0");
    ithem.setAtributs(std::move(temp));
    sGeometry geometry;
    geometry.x = paramsMap.find("x")->second;
    geometry.y = paramsMap.find("y")->second;
    geometry.len = paramsMap.find("l")->second;
    geometry.hig = paramsMap.find("h")->second;
    ithem.setGeometry(geometry);
    (page_)->addIthem(ithem);
}



void Editor::moveVertical(ID id, Pos y){
    auto result = (page_)->find(id);
    auto geometry = result.getGeometry();
    geometry.y += y;
    result.setGeometry(geometry);
}


void Editor::moveHorizontal(ID id, Pos x){
    auto result = (page_)->find(id);
    auto geometry = result.getGeometry();
    geometry.x += x;
    result.setGeometry(geometry);
}



void Editor::changeIthemColor(ID id, color::sColor color){

}

void Editor::changeIthemLength(ID id, length len){
    auto result = (page_)->find(id);
    auto geometry = result.getGeometry();
    geometry.len += len;
    result.setGeometry(geometry);
}

void Editor::changeIthemHeight(ID id, length high){
    auto result = (page_)->find(id);
    auto geometry = result.getGeometry();
    geometry.hig += high;
    result.setGeometry(geometry);
}

void Editor::removeIthem(ID id){
    (page_)->removeIthem(id);   
}
void Editor::setPage(std::shared_ptr<Page> page){
    this->page_ = page;
}

ID Editor::genereytId()
{
    return ithemCaont++;
}
