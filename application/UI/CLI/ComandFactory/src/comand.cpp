#include "comand.h"

#include "../../../../Dacument/Editor/editor.h"

#include <stdexcept>
#include <algorithm>
#include <../../../../application.h>



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AComand::setOptionValue(std::shared_ptr<std::unordered_map<Options, Params>> optionsValue){
    this->optionMap = optionsValue;
}

std::unordered_map<Options, Params> &AComand::getOptionValue(){
    return *optionMap;
}








/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Undo::execute(){
    if(isOptionsValid()){
        Editor::getEditor().undo();
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> Undo::returnCopy(){
    return std::make_shared<Undo>();
}

bool Undo::isOptionsValid(){
    return getOptionValue().empty();
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Redo::execute(){
    if(isOptionsValid()){
        Editor::getEditor().redo();
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> Redo::returnCopy(){
    return std::make_shared<Redo>();
}

bool Redo::isOptionsValid(){
    return getOptionValue().empty();
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void New::execute(){
    if(isOptionsValid()){
        std::shared_ptr<Page> newPage = std::make_shared<Page>();
        std::shared_ptr<Slide> slide = Application::getAplication().getSlide();
        Editor::getEditor().proces(std::make_shared<act::PushBack>(slide, newPage));        
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> New::returnCopy(){
    return std::make_shared<New>();
}

bool New::isOptionsValid(){
    return getOptionValue().empty();
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AddPage::execute(){
    if(isOptionsValid()){
        std::shared_ptr<Slide> slide = Application::getAplication().getSlide();
        std::shared_ptr<Page> newPage = std::make_shared<Page>();
        Editor::getEditor().proces(std::make_shared<act::AddPage>(slide, pos, newPage));
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> AddPage::returnCopy(){
    return std::make_shared<AddPage>();
}

bool AddPage::isOptionsValid(){
    if(getOptionValue().size()!= 1){
        return false;
    }
    auto option = this->getOptionValue().find(std::string("pos"));
    if(option == this->getOptionValue().end()){
        option = this->getOptionValue().find(std::string("p"));
        if(option == this->getOptionValue().end()){
            return false;    
        }
    }
    if(option->second.vectorInteger.size() != 1){
        return false;
    }
    this->pos = option->second.vectorInteger.front();
    return true;
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PushBackPage::execute(){
    if(isOptionsValid()){
        std::shared_ptr<Page> newPage = std::make_shared<Page>();
        std::shared_ptr<Slide> slide = Application::getAplication().getSlide();
        Editor::getEditor().proces(std::make_shared<act::PushBack>(slide, newPage)); 
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> PushBackPage::returnCopy(){
    return std::make_shared<PushBackPage>();
}

bool PushBackPage::isOptionsValid(){    
    return getOptionValue().empty();
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PopBackPage::execute(){
    if(isOptionsValid()){
        std::shared_ptr<Slide> slide = Application::getAplication().getSlide();
        Editor::getEditor().proces(std::make_shared<act::PoPBack>(slide)); 
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> PopBackPage::returnCopy(){
    return std::make_shared<PopBackPage>();
}

bool PopBackPage::isOptionsValid(){
    return getOptionValue().empty();
}






//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RemovePage::execute(){
    if(isOptionsValid()){
        std::shared_ptr<Slide> slide = Application::getAplication().getSlide();
        std::shared_ptr<Page> newPage = std::make_shared<Page>();

        Editor::getEditor().proces(std::make_shared<act::RemovePage>(slide, pos));
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> RemovePage::returnCopy(){
    return std::make_shared<RemovePage>();
}

bool RemovePage::isOptionsValid(){
    if(getOptionValue().size()!= 1){
        return false;
    }
    auto option = this->getOptionValue().find(std::string("pos"));
    if(option == this->getOptionValue().end()){
        option = this->getOptionValue().find(std::string("p"));
        if(option == this->getOptionValue().end()){
            return false;    
        }
    }
    if(option->second.vectorInteger.size() != 1){
        return false;
    }
    this->pos = option->second.vectorInteger.front();
    return true;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OpenPage::execute(){
    if(isOptionsValid()){
        Application::getAplication().openPage(pos);
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> OpenPage::returnCopy()
{
    return std::make_shared<OpenPage>();
}

bool OpenPage::isOptionsValid(){    
    if(getOptionValue().size()!= 1){
        return false;
    }
    auto option = this->getOptionValue().find(std::string("pos"));
    if(option == this->getOptionValue().end()){
        option = this->getOptionValue().find(std::string("p"));
        if(option == this->getOptionValue().end()){
            return false;    
        }
    }
    if(option->second.vectorInteger.size() != 1){
        return false;
    }
    this->pos = option->second.vectorInteger.front();
    return true;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SwapPage::execute(){
    if(isOptionsValid()){
        
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> SwapPage::returnCopy(){
    return std::make_shared<SwapPage>();
}

bool SwapPage::isOptionsValid(){
    if(getOptionValue().size()!= 1){
        return false;
    }
    auto option = this->getOptionValue().find(std::string("pos"));
    if(option == this->getOptionValue().end()){
        option = this->getOptionValue().find(std::string("p"));
        if(option == this->getOptionValue().end()){
            return false;    
        }
    }
    if(option->second.vectorInteger.size() != 2){
        return false;
    }
    this->vecInt = std::move(option->second.vectorInteger);
    return true;
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AddShape::execute(){
    if(isOptionsValid()){
        //...
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> AddShape::returnCopy(){
    return std::make_shared<AddShape>();
}

bool AddShape::isOptionsValid(){
    std::unordered_map<Options, Params>& optionValuMap = getOptionValue();
    auto option = optionValuMap.find("g");
    if(option == optionValuMap.end()){
        option = optionValuMap.fin("gemetry")
        if(option == optionValuMap.end()){

            
        }
    }
}

bool AddShape::ifIsOptionGeometry(){
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RemoveIthem::execute(){
    if(isOptionsValid()){
        std::shared_ptr<Page> page = Application::getAplication().getPage();
        Editor::getEditor().proces(std::make_shared<act::RemoveIthem>(page, id));
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> RemoveIthem::returnCopy(){
    return std::make_shared<RemoveIthem>();
}

bool RemoveIthem::isOptionsValid(){
    if(getOptionValue().size()!= 1){
        return false;
    }
    auto option = this->getOptionValue().find(std::string("id"));
    if(option == this->getOptionValue().end()){
        option = this->getOptionValue().find(std::string("i"));
        if(option == this->getOptionValue().end()){
            return false;    
        }
    }
    if(option->second.vectorInteger.size() != 1){
        return false;
    }
    this->id = option->second.vectorInteger.front();
    return true;
}






//////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool AChangeIthemGeometry::isOptionsValid(){
    if(getOptionValue().size()!= 2){
        return false;
    }
    auto option = this->getOptionValue().find(std::string("id"));
    if(option == this->getOptionValue().end()){
        option = this->getOptionValue().find(std::string("i"));
        if(option == this->getOptionValue().end()){
            return false;    
        }
    }
    if(option->second.vectorInteger.size() != 1){
        return false;
    }
    this->id = option->second.vectorInteger.front();
    option = this->getOptionValue().find(std::string("d"));
    if(option == this->getOptionValue().end()){
        return false;    
    }
    if(option->second.vectorInteger.size() != 1){
        return false;
    }
    this->changeSize = option->second.vectorInteger.front();
    return true;
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MoveVertical::execute(){
    if(isOptionsValid()){
        Ithem& ithem =  Application::getAplication().getPage()->find(id);
        sGeometry geometry = ithem.getGeometry(); 
        geometry.y = geometry.y + changeSize;
        Editor::getEditor().proces(std::make_shared<act::ChangeIthemGeometry>(ithem, geometry));
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> MoveVertical::returnCopy(){
    return std::make_shared<MoveVertical>();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MoveHorizontal::execute(){
    if(isOptionsValid()){
        Ithem& ithem =  Application::getAplication().getPage()->find(id);
        sGeometry geometry = ithem.getGeometry(); 
        geometry.x = geometry.x + changeSize;
        Editor::getEditor().proces(std::make_shared<act::ChangeIthemGeometry>(ithem, geometry));
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> MoveHorizontal::returnCopy(){
    return std::make_shared<MoveHorizontal>();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ChangeIthemLenghth::execute(){
    if(isOptionsValid()){
        Ithem& ithem =  Application::getAplication().getPage()->find(id);
        sGeometry geometry = ithem.getGeometry(); 
        geometry.len = geometry.len + changeSize;
        Editor::getEditor().proces(std::make_shared<act::ChangeIthemGeometry>(ithem, geometry));
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> ChangeIthemLenghth::returnCopy(){
    return std::make_shared<ChangeIthemLenghth>();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ChangeIthemHeight::execute(){
    if(isOptionsValid()){
        Ithem& ithem =  Application::getAplication().getPage()->find(id);
        sGeometry geometry = ithem.getGeometry(); 
        geometry.hig = geometry.hig + changeSize;
        Editor::getEditor().proces(std::make_shared<act::ChangeIthemGeometry>(ithem, geometry));
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> ChangeIthemHeight::returnCopy(){
    return std::make_shared<ChangeIthemHeight>();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PrintSlide::execute(){
    Visualizer::getVisualizer().printSlide(Application::getAplication().getSlide());
}

std::shared_ptr<IComand> PrintSlide::returnCopy(){
    return std::make_shared<PrintSlide>();
}

bool PrintSlide::isOptionsValid()
{
    return getOptionValue().empty();
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PrintPage::execute(){
    if(isOptionsValid()){
        Visualizer::getVisualizer().printPage(Application::getAplication().getPage());
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> PrintPage::returnCopy(){
    return std::make_shared<PrintPage>();
}

bool PrintPage::isOptionsValid(){
    if(getOptionValue().size()!= 1){
        return false;
    }
    auto option = this->getOptionValue().find(std::string("pos"));
    if(option == this->getOptionValue().end()){
        option = this->getOptionValue().find(std::string("p"));
        if(option == this->getOptionValue().end()){
            return false;    
        }
    }
    if(option->second.vectorInteger.size() != 1){
        return false;
    }
    this->pos = option->second.vectorInteger.front();
    return true;
}
