#include "comand.h"
#include "../../../../Dacument/slideMeneger/slideMeneger.h"


#include <stdexcept>

void AComand::setParams(std::shared_ptr<Params> params){
    this->params = params;
}

const Params &AComand::getParams() const{
    return *params;
}

void New::execute(){
    if(paramsIsValid()){
        SlideMeneger::newSlide();
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool New::paramsIsValid(){
    return getParams().integerArguments.empty() && getParams().stringArguments.empty();
}

void AddPage::execute(){
    if(paramsIsValid()){
        SlideMeneger::addPage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool AddPage::paramsIsValid()
{
    return (getParams().integerArguments.size() == 1) && (getParams().stringArguments.empty());
}

void RemovePage::execute(){
    if(paramsIsValid()){
        SlideMeneger::removePage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool RemovePage::paramsIsValid()
{
    return (getParams().integerArguments.size() == 1) && (getParams().stringArguments.empty());
}

void OpenPage::execute(){
    if(paramsIsValid()){
        SlideMeneger::openPage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool OpenPage::paramsIsValid()
{
    return (getParams().integerArguments.size() == 1) && (getParams().stringArguments.empty());
}

void AddShape::execute(){
    if(paramsIsValid()){
        SlideMeneger::addShape(getParams().stringArguments.front(), getParams().integerArguments[0], getParams().integerArguments[1], getParams().integerArguments[2], getParams().integerArguments[3]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool AddShape ::paramsIsValid(){
    return (getParams().integerArguments.size() == 4) && (getParams().stringArguments.size() == 1);
}

void MoveVertical::execute(){
    if(paramsIsValid()){
        SlideMeneger::moveVertical(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool MoveVertical::paramsIsValid(){
    return (getParams().integerArguments.size() == 2) && (getParams().stringArguments.empty());
}

void MoveHorizontal::execute(){
    if(paramsIsValid()){
        SlideMeneger::moveHorizontal(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool MoveHorizontal::paramsIsValid(){
    return (getParams().integerArguments.size() == 2) && (!getParams().stringArguments.empty());
}

void ChangeIthemLenghth::execute(){
    if(paramsIsValid()){
        SlideMeneger::changeIthemLength(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}

bool ChangeIthemLenghth::paramsIsValid()
{
    return (getParams().integerArguments.size() == 2) && (getParams().stringArguments.empty());
}

void ChangeIthemHeight::execute(){
    if(paramsIsValid()){
        SlideMeneger::changeIthemHeight(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}
bool ChangeIthemHeight::paramsIsValid()
{
    return (getParams().integerArguments.size() == 2) && (getParams().stringArguments.empty());
}

void RemoveIthem::execute(){
    if(paramsIsValid()){
        SlideMeneger::removeIthem(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: parameters are invalid");
    }
}
bool RemoveIthem::paramsIsValid()
{
    return (getParams().integerArguments.size() == 1) && (getParams().stringArguments.empty());
}
