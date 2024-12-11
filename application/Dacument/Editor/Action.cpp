#include "Action.h"

namespace act{

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PushBack::PushBack(std::shared_ptr<Slide> slide, std::shared_ptr<Page> page){
    this->slide = slide;
    this->page = page;
}

void PushBack::doo(){
    this->slide->pushBackPage(page);
}

std::shared_ptr<IAction> PushBack::returnUndoAction(){
    return std::make_shared<PoPBack>(this->slide);
}





///////////////////////////////////////////////////////////////////////////////////////////////////////////////
PoPBack::PoPBack(std::shared_ptr<Slide> slide){
    this->slide = slide;
    this->page = *(--(slide->end()));
}

void PoPBack::doo(){
    slide->popBackPage();
}

std::shared_ptr<IAction> PoPBack::returnUndoAction(){
    return std::make_shared<PushBack>(slide, page);
}





///////////////////////////////////////////////////////////////////////////////////////////////////////////////
AddPage::AddPage(std::shared_ptr<Slide> slide, Pos pos, std::shared_ptr<Page> page){
    this->slide = slide;
    this->page = page;
    this->iterator = std::next(slide->begin(), pos);
}

void AddPage::doo(){
    slide->insertPage(iterator, page);
}

std::shared_ptr<IAction> AddPage::returnUndoAction(){
    return std::make_shared<RemovePage>(slide, std::distance(slide->begin(), iterator));
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////
RemovePage::RemovePage(std::shared_ptr<Slide> slide, Pos pos){
    this->slide = slide;
    this->iterator = std::next(slide->begin(), pos);
    this->page = *iterator;
    this->pos = std::distance(slide->begin(), iterator);
}

void RemovePage::doo(){
    slide->removePage(iterator);
}

std::shared_ptr<IAction> RemovePage::returnUndoAction(){
    return std::make_shared<AddPage>(slide, pos, page);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////
SwapPages::SwapPages(std::shared_ptr<Slide> slide, std::shared_ptr<Page> page1, std::shared_ptr<Page> page2){
    this->slide = slide;
    this->page1 = page1;
    this->page2 = page2; 
}

void SwapPages::doo(){
    slide->swapPage(page1, page2);
}

std::shared_ptr<IAction> SwapPages::returnUndoAction(){
    return std::make_shared<SwapPages>(slide, page2, page1);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////
AddShape::AddShape(std::shared_ptr<Page> page, std::shared_ptr<Ithem> ithem){
    this->page = page;
    this->ithem = ithem;
}

void AddShape::doo(){
    page->addIthem(*ithem);
}

std::shared_ptr<IAction> AddShape::returnUndoAction(){
    return std::make_shared<RemoveIthem>(page, ithem->getID());
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////
RemoveIthem::RemoveIthem(std::shared_ptr<Page> page, ID id){
    this->page = page;
    this->ithem = std::make_shared<Ithem>(page->find(id));

}

void RemoveIthem::doo(){
    page->removeIthem(ithem->getID());
}

std::shared_ptr<IAction> RemoveIthem::returnUndoAction(){
    return std::make_shared<AddShape>(page, ithem);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////
ChangeIthemGeometry::ChangeIthemGeometry(Ithem& ithem, const sGeometry &geometry) : ithem_(ithem){
    this->geometry = geometry;
}

void ChangeIthemGeometry::doo(){
    sGeometry temp = ithem_.getGeometry();
    ithem_.setGeometry(geometry);
    this->geometry = temp;
}

std::shared_ptr<IAction> ChangeIthemGeometry::returnUndoAction(){
    return std::make_shared<ChangeIthemGeometry>(ithem_, geometry);
}




}//namespace act