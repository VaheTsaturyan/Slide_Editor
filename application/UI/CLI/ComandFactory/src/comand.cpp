#include "comand.h"

#include "../../../../Dacument/Editor/editor.h"

#include <stdexcept>
#include <algorithm>
#include <../../../../application.h>
#include <fstream>

const std::string HELP_TXT_PATH = std::string("/home/vts/repos/Slide_Editor/help.txt");





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
        std::shared_ptr<Slide> slide = Application::instance()->getSlide();
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
        std::shared_ptr<Slide> slide = Application::instance()->getSlide();
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
        std::shared_ptr<Slide> slide = Application::instance()->getSlide();
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
        std::shared_ptr<Slide> slide = Application::instance()->getSlide();
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
        std::shared_ptr<Slide> slide = Application::instance()->getSlide();
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
        Application::instance()->openPage(pos);
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
        std::shared_ptr<Slide> slide = Application::instance()->getSlide();
        std::shared_ptr<Page> page1 = *(std::next(slide->begin(), vecInt[0]));
        std::shared_ptr<Page> page2 = *(std::next(slide->begin(), vecInt[1]));
        Editor::getEditor().proces(std::make_shared<act::SwapPages>(slide, page1, page2));
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
        std::shared_ptr<Ithem> ithem = std::make_shared<Ithem>(Editor::getEditor().genereytId());
        ithem->setGeometry(shpInit.getGeometry());
        ithem->setAtributs(std::move(shpInit.getAtributs()));
        Editor::getEditor().proces(std::make_shared<act::AddShape>(Application::instance()->getPage(), ithem));
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> AddShape::returnCopy(){
    return std::make_shared<AddShape>();
}

bool AddShape::isOptionsValid(){
    std::unordered_map<Options, Params>& optionValuMap = getOptionValue();
    std::shared_ptr<std::unordered_map<std::string, Params>> ptrOptionValuMap = std::make_shared<std::unordered_map<std::string, Params>>(optionValuMap);
    this->shpInit.setOptionValueMap(ptrOptionValuMap);
    return shpInit.initiliz();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AddText::execute(){
    if(isOptionsValid()){
        std::shared_ptr<Ithem> ithem = std::make_shared<Ithem>(Editor::getEditor().genereytId());
        ithem->setGeometry(txtInit.getGeometry());
        sAtributs atr = txtInit.getAtributs();
        atr.map.emplace(std::string("type"), std::string("text"));
        ithem->setAtributs(std::move(atr));
        Editor::getEditor().proces(std::make_shared<act::AddShape>(Application::instance()->getPage(), ithem));
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> AddText::returnCopy(){
    return std::make_shared<AddText>();
}

bool AddText::isOptionsValid(){
    std::unordered_map<Options, Params>& optionValuMap = getOptionValue();
    std::shared_ptr<std::unordered_map<std::string, Params>> ptrOptionValuMap = std::make_shared<std::unordered_map<std::string, Params>>(optionValuMap);
    this->txtInit.setOptionValueMap(ptrOptionValuMap);
    return txtInit.initiliz();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RemoveIthem::execute(){
    if(isOptionsValid()){
        std::shared_ptr<Page> page = Application::instance()->getPage();
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
        Ithem& ithem =  Application::instance()->getPage()->find(id);
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
        Ithem& ithem =  Application::instance()->getPage()->find(id);
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
        Ithem& ithem =  Application::instance()->getPage()->find(id);
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
        Ithem& ithem =  Application::instance()->getPage()->find(id);
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
    Visualizer visualizer;
    visualizer.printSlide(Application::instance()->getSlide());
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
        Visualizer visualizer;
        visualizer.printPage(Application::instance()->getPage());
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DrawPage::execute(){
    if(isOptionsValid()){
        Visualizer visualizer;
        visualizer.drowPage(Application::instance()->getPage(), path);
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}


bool DrawPage::isOptionsValid(){
    if(getOptionValue().size()!= 2){
        return false;
    }
    auto option = this->getOptionValue().find(std::string("pos"));
    if(option == this->getOptionValue().end()){
        option = this->getOptionValue().find(std::string("p"));
        if(option == this->getOptionValue().end()){
            return false;    
        }
    }
    if(option->second.vectorInteger.size() != 1 || !(option->second.vectorString.empty())){
        return false;
    }
    this->pos = option->second.vectorInteger.front();
    option = this->getOptionValue().find(std::string("path"));
    if(option == this->getOptionValue().end()){
        return false;    
    }
    if(option->second.vectorString.size() != 1 || !(option->second.vectorInteger.empty())){
        return false;
    }
    this->path = option->second.vectorString.front();
    return true;
}

std::shared_ptr<IComand> DrawPage::returnCopy(){
    return std::make_shared<DrawPage>();
}


/////////////////////////////////////////////////////////////////////////////////////////////
void Open::execute(){
    if(isOptionsValid()){
        if((Application::instance()->getSlide()->getPageCount() != 0)){
            Loger::getLoger().print("You currently have a slide open. Do you want to save it?y(+path)/n\n");
            Parser parser;
            parser.input(std::cin);
            parser.parsing();
            ComandFactory factory;
            factory.registorComand(std::string("yes"), std::make_shared<YesSave>());
            factory.registorComand(std::string("no"), std::make_shared<DontSave>());
            factory.registorComand(std::string("y"), std::make_shared<YesSave>());
            factory.registorComand(std::string("n"), std::make_shared<DontSave>());
            std::shared_ptr<IComand> comand = factory.createComand(parser.getComand());
            comand->setOptionValue(parser.getOptionsValue());
            comand->execute();    
        }       
        Sterializer streilizer;
        Application::instance()->openSlide(streilizer.open(this->path));
        Editor::getEditor().clear();
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> Open::returnCopy(){
    return std::make_shared<Open>();
}

bool Open::isOptionsValid(){
    if(getOptionValue().size()!= 1){
        return false;
    }
    auto option = this->getOptionValue().find(std::string("path"));
    if(option == this->getOptionValue().end()){
        option = this->getOptionValue().find(std::string("p"));
        if(option == this->getOptionValue().end()){
            return false;    
        }
    }
    if(option->second.vectorString.size() != 1 || !option->second.vectorInteger.empty()){
        return false;
    }
    this->path = option->second.vectorString.front();
    return true;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
void Save::execute(){
    if(isOptionsValid()){
        Sterializer streilizer;
        streilizer.save(path, Application::instance()->getSlide());
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> Save::returnCopy(){
    return std::make_shared<Save>();
}

bool Save::isOptionsValid(){
    if(getOptionValue().size()!= 1){
        return false;
    }
    auto option = this->getOptionValue().find(std::string("path"));
    if(option == this->getOptionValue().end()){
        option = this->getOptionValue().find(std::string("p"));
        if(option == this->getOptionValue().end()){
            return false;    
        }
    }
    if(option->second.vectorString.size() != 1 || !option->second.vectorInteger.empty()){
        return false;
    }
    this->path = option->second.vectorString.front();
    return true;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
void YesSave::execute(){
    if(isOptionsValid()){
        Sterializer streilizer;
        streilizer.save(path, Application::instance()->getSlide());
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> YesSave::returnCopy(){
    return std::make_shared<YesSave>();
}

bool YesSave::isOptionsValid(){
    if(getOptionValue().size()!= 1){
        return false;
    }
    auto option = this->getOptionValue().find(std::string("path"));
    if(option == this->getOptionValue().end()){
        option = this->getOptionValue().find(std::string("p"));
        if(option == this->getOptionValue().end()){
            return false;    
        }
    }
    if(option->second.vectorString.size() != 1 || !option->second.vectorInteger.empty()){
        return false;
    }
    this->path = option->second.vectorString.front();
    return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void DontSave::execute(){
    if(isOptionsValid()){
        return;
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> DontSave::returnCopy(){
    return std::make_shared<DontSave>();
}

bool DontSave::isOptionsValid(){    
    return getOptionValue().empty();
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Help::execute(){
    if(isOptionsValid()){
        std::ifstream file;
        file.open(HELP_TXT_PATH);
            if (!file) {
                throw std::runtime_error("The parameters are invalid\n");
            }

        std::string line;
        while (std::getline(file, line)) {
            Loger::getLoger().print(line);
            Loger::getLoger().print("\n");
        }

        file.close();
    }else{
        throw std::runtime_error("The parameters are invalid\n");
    }
}

std::shared_ptr<IComand> Help::returnCopy(){
    return std::make_shared<Help>();
}

bool Help::isOptionsValid(){    
    return getOptionValue().empty();
}
