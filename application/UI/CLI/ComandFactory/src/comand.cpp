#include "comand.h"
#include "../../../../Dacument/slideMeneger/slideMeneger.h"


#include <stdexcept>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AComand::setParams(std::shared_ptr<Params> params){
    this->params = params;
}

void AComand::setOptions(std::shared_ptr<Options> options){
    this->options = options;
}

void AComand::setEditor(std::shared_ptr<Editor> editor){
    this->editor = editor; 
}

const Options& AComand::getOptions() const{
    return *options;
}

const Params &AComand::getParams() const{
    return *params;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void New::execute(){
    if(optionsIsValid() && paramsIsValid()){
        editor->newSlide();
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool New::paramsIsValid(){
    return getParams().integerArguments.empty() && getParams().stringArguments.empty();
}

bool New::optionsIsValid()
{
    return this->getOptions().empty();
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AddPage::execute(){
    if(optionsIsValid() && paramsIsValid()){
        editor->addPage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool AddPage::paramsIsValid(){
    return (getParams().integerArguments.size() == 1) && (getParams().stringArguments.empty());
}

bool AddPage::optionsIsValid(){
    return this->getOptions().size() == 1 && (this->getOptions().front() == "pos" || this->getOptions().front() == "p");
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RemovePage::execute(){
    if(optionsIsValid() && paramsIsValid()){
        editor->removePage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool RemovePage::paramsIsValid()
{
    return (getParams().integerArguments.size() == 1) && (getParams().stringArguments.empty());
}


bool RemovePage::optionsIsValid(){
    return this->getOptions().size() == 1 && (this->getOptions().front() == "pos" || this->getOptions().front() == "p");
}






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OpenPage::execute(){
    if(optionsIsValid() && paramsIsValid()){
        editor->openPage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool OpenPage::paramsIsValid()
{
    return (getParams().integerArguments.size() == 1) && (getParams().stringArguments.empty());
}

bool OpenPage::optionsIsValid(){
    return this->getOptions().size() == 1 && (this->getOptions().front() == "pos" || this->getOptions().front() == "p");
}







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AddShape::AddShape(){
    this->initOptionsMap();
    this->initTypeMap();
}

void AddShape::execute()
{
    if(optionsIsValid() && paramsIsValid()){
        editor->addShape( getParams().stringArguments.front(),
                                getParams().integerArguments[0], 
                                getParams().integerArguments[1], 
                                getParams().integerArguments[2], 
                                getParams().integerArguments[3]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
    }
}

bool AddShape ::paramsIsValid(){
    if( getParams().integerArguments.size() == 4 && getParams().stringArguments.size() == 1 ){
        return typeMap.find(getParams().stringArguments.front()) != typeMap.end();
    }
    return false;
}

bool AddShape::optionsIsValid(){
    auto opt = this->getOptions();
    if(opt.size() != 5){
        return false;
    }
    for(auto el : opt){
        if(optionsMap.find(el) == optionsMap.end()){
            return false;
        }
    }
    return true;
}

void AddShape::initOptionsMap(){
    this->optionsMap.emplace("x");
    this->optionsMap.emplace("y");
    this->optionsMap.emplace("l");
    this->optionsMap.emplace("h");
    this->optionsMap.emplace("t");
}

void AddShape::initTypeMap(){
    this->typeMap.emplace("rectangle");
    this->typeMap.emplace("ellipse");
    this->typeMap.emplace("r");
    this->typeMap.emplace("e");
}







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RemoveIthem::execute(){
    if(optionsIsValid()&&paramsIsValid()){
        editor->removeIthem(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool RemoveIthem::optionsIsValid(){
    return this->getOptions().size() == 1 && (this->getOptions().front() == "id" || this->getOptions().front() == "i");
}
bool RemoveIthem::paramsIsValid()
{
    return (getParams().integerArguments.size() == 1) && (getParams().stringArguments.empty());
}






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool AChangeIthemGeometry::paramsIsValid(){
    return (getParams().integerArguments.size() == 2) && (getParams().stringArguments.empty());
}

bool AChangeIthemGeometry::optionsIsValid(){
    auto options = getOptions();
    if(options.size() == 2){
        for(auto el : options){
            if(optionsMap.find(el) == optionsMap.end()){
                return false;
            }
        }
        return true;
    }
    return false;
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MoveVertical::MoveVertical(){
    initOptionMap();
}

void MoveVertical::execute()
{
    if(optionsIsValid()&&paramsIsValid()){
        editor->moveVertical(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}


void MoveVertical::initOptionMap(){
 
    optionsMap.emplace("down");
    optionsMap.emplace("up");
    optionsMap.emplace("id");
    optionsMap.emplace("d");
    optionsMap.emplace("u");
    optionsMap.emplace("i");

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MoveHorizontal::MoveHorizontal(){
    initOptionMap();
}

void MoveHorizontal::execute(){
    if(optionsIsValid()&&paramsIsValid()){
        editor->moveHorizontal(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

void MoveHorizontal::initOptionMap(){
    optionsMap.emplace("right");
    optionsMap.emplace("left");
    optionsMap.emplace("id");
    optionsMap.emplace("r");
    optionsMap.emplace("l");
    optionsMap.emplace("i");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ChangeIthemLenghth::ChangeIthemLenghth(){
    initOptionMap();
}


void ChangeIthemLenghth::execute(){
    if(optionsIsValid()&&paramsIsValid()){
        editor->changeIthemLength(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

void ChangeIthemLenghth::initOptionMap(){
    optionsMap.emplace("add");
    optionsMap.emplace("left");
    optionsMap.emplace("id");
    optionsMap.emplace("r");
    optionsMap.emplace("l");
    optionsMap.emplace("i");    
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ChangeIthemHeight::ChangeIthemHeight(){
    initOptionMap();
}


void ChangeIthemHeight::execute(){
    if(optionsIsValid()&&paramsIsValid()){
        editor->changeIthemHeight(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}
void ChangeIthemHeight::initOptionMap(){
    optionsMap.emplace("right");
    optionsMap.emplace("left");
    optionsMap.emplace("id");
    optionsMap.emplace("r");
    optionsMap.emplace("l");
    optionsMap.emplace("i");
}





