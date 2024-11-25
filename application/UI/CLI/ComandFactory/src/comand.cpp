#include "comand.h"



#include <stdexcept>
#include <algorithm>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AComand::setParams(std::shared_ptr<Params> params){
    this->params = params;
}

void AComand::setOptions(std::shared_ptr<Options> options){
    this->options = options;
}


Options& AComand::getOptions(){
    return *options;
}

Params &AComand::getParams(){
    return *params;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void New::execute(){
    if(optionsIsValid() && paramsIsValid()){
        Editor::getEditor().newSlide();
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
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
        Editor::getEditor().addPage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
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
        Editor::getEditor().removePage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
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
        Editor::getEditor().openPage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
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


#include <iostream>
void AddShape::execute()
{
    if(optionsIsValid() && paramsIsValid()){
        Editor::getEditor().addShape( getParams().stringArguments.front(), genereytMapOpsonValue());
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
    }
}

bool AddShape::paramsIsValid(){
    if( getParams().integerArguments.size() == 4 && getParams().stringArguments.size() == 1 ){
        return (typeMap.find(getParams().stringArguments.front()) != typeMap.end());
    }
    return false;
}


bool AddShape::optionsIsValid(){
    auto& opt = this->getOptions();
    if(opt.size() != 5){
        return false;
    }
    for(auto it = opt.begin(); it != opt.end() ; ++it ){
        if(optionsMap.find(*it) == optionsMap.end()){
            return false;
        }
    }
    opt.erase(std::find(opt.begin(), opt.end() , "t"));
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


std::unordered_map<std::string, int> AddShape::genereytMapOpsonValue(){
    auto options = getOptions();
    auto params = getParams();
    std::unordered_map<std::string, int> map;
    if(options.size() != params.integerArguments.size()){
        throw std::runtime_error("CLI: parameters are invalid\n");
    }
    for(int i = 0 ; i < params.integerArguments.size(); ++i){

        map.emplace(options[i], params.integerArguments[i]);
    }
    return map;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RemoveIthem::execute(){
    if(optionsIsValid()&&paramsIsValid()){
        Editor::getEditor().removeIthem(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
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
        Editor::getEditor().moveVertical(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
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
        Editor::getEditor().moveHorizontal(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
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
        Editor::getEditor().changeIthemLength(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
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
        Editor::getEditor().changeIthemHeight(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
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


/////////////////////////////////////////////////////////////
void pushBackPage::execute(){
    if(optionsIsValid() && paramsIsValid()){
        Editor::getEditor().pushBackPage();
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
    }
}

bool pushBackPage::paramsIsValid(){
    return (getParams().integerArguments.empty()) && (getParams().stringArguments.empty());
}

bool pushBackPage::optionsIsValid(){
    return  this->getOptions().empty();
}


////////////////////////////////////////////////////////////////////
void popBackPage::execute(){
    if(optionsIsValid() && paramsIsValid()){
        Editor::getEditor().popBackPage();
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
    }
}

bool popBackPage::paramsIsValid(){
    return (getParams().integerArguments.empty()) && (getParams().stringArguments.empty());
}

bool popBackPage::optionsIsValid(){
    return  this->getOptions().empty();
}



///////////////////////////////////////////////////////////////////////////////////
void printSlide::execute(){   
    if(optionsIsValid() && paramsIsValid()){
        Visualizer::getVisualizer().printSlide();
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
    }
}

bool printSlide::paramsIsValid(){
    return this->getParams().integerArguments.empty() && this->getParams().stringArguments.empty();
}

bool printSlide::optionsIsValid(){
    return this->getOptions().empty();
}


void printPage::execute(){   
    if(optionsIsValid() && paramsIsValid()){
        Visualizer::getVisualizer().printPage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid\n");
    }
}

bool printPage::paramsIsValid(){
    return this->getParams().integerArguments.size() == 1 && this->getParams().stringArguments.empty();
}

bool printPage::optionsIsValid(){
    return this->getOptions().size() == 1;
}
