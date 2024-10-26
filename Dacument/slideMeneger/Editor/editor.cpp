#include "editor.h"

/*

void Editor::addSquare(pos x, pos y, length len){

}

void Editor::addElips(pos x, pos y, length len, lenght high){
    page_->push(std::make_shared<> )
}

*/
void Editor::addRectangle(pos x, pos y, length len, lenght high){
    page_->addIthem(std::make_shared<Rectangle>(genereytId()));
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
    geometry.high += high;
    result->setGeometry(geometry);
}

void Editor::removeIthem(ID id){
    page_->removeIthem(id);   
}

void Editor::setPage(std::shared_ptr<Page> page){
    this->page_ = page;
}

Id Editor::genereytId()
{
    return ithemCaont++;
}
