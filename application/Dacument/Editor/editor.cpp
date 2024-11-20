#include "editor.h"


void Editor::setSlide(std::shared_ptr<Slide> slide){
    this->slide_ = slide_;
}


void Editor::newSlide()
{
    slide_.newSlide();
}

void Editor::addPage(Pos pos)
{
    if(pos > slide_.getPageCount()){
        std::runtime_error("CLI: Unable to add page with specified index");
    }
    auto sld = slide_.getPages();
    auto it = sld.begin();
    for(int i = 0; i < pos; ++i){ ++it; }
    sld.emplace(it, std::make_shared<Page>());
}


void Editor::removePage(Pos pos)
{
    auto sld = slide_.getPages();
    auto it = sld_.begin();
    for(int i = 0; i < pos; ++i){ ++it; }
    sld.erase(it);
}



void Editor::swopPages(Pos first, Pos second)
{
    if(first > slide_.getPageCount() || second > slide_.getPageCount()){
        std::runtime_error("CLI: The specified pages or one of them does not exist");
    }
}


void Editor::openPage(Pos pos)
{
    if(pos > slide_.getPageCount()){
        std::runtime_error("CLI: Unable to add page with specified index");
    }
    editor.setPage(slide_.getPages()[pos]);
}



void Editor::addShape(std::string type, Pos x, Pos y, length len, length high)
{
    std::shared_ptr<AItem> ithem = std::make_shared<AItem>(genereytId());
    sAtributs temp;
    temp.map.emplace(atr::Type, type);
    temp.map.emplace(atr::Color, "0.0.0");
    ithem->setAtributs(std::move(temp));
    ithem->setGeometry(sGeometry(x,y,len,high));
    page_->addIthem(ithem);
}



void Editor::moveVertical(ID id, Pos y){
    auto result = page_->find(id);
    auto geometry = result->getGeometry();
    geometry.y += y;
    result->setGeometry(geometry);
}


void Editor::moveHorizontal(ID id, Pos x){
    auto result = page_->find(id);
    auto geometry = result->getGeometry();
    geometry.x += x;
    result->setGeometry(geometry);
}



void Editor::changeIthemColor(ID id, color::sColor color){

}

void Editor::changeIthemLength(ID id, length len){
    auto result = page_->find(id);
    auto geometry = result->getGeometry();
    geometry.len += len;
    result->setGeometry(geometry);
}

void Editor::changeIthemHeight(ID id, length high){
    auto result = page_->find(id);
    auto geometry = result->getGeometry();
    geometry.hig += high;
    result->setGeometry(geometry);
}

void Editor::removeIthem(ID id){
    page_->removeIthem(id);   
}

void Editor::setPage(std::shared_ptr<Page> page){
    this->page_ = page;
}

ID Editor::genereytId()
{
    return ithemCaont++;
}
