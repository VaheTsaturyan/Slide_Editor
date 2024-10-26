#include "comand.h"
#include <stdexcept>

void AComand::setParams(Params &&params){
    this->params.integerArguments = std::move(params.integerArguments);
    this->params.stringArguments = std::move(params.stringArguments);
}

const Params &AComand::getParams() const{
    return params;
}

void New::execute(){
    if(paramsIsValid()){
        SlideMeneger::newSlide();
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool New::paramsIsValid(){
    return !(getParams().integerArguments.empty() || getParams().stringArguments.empty());
}

void AddPage::execute(){
    if(paramsIsValid()){
        SlideMeneger::addPage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool AddPage::paramsIsValid()
{
    return (getParams().integerArguments.size() == 1) && (!getParams().stringArguments.empty());
}

void RemovePage::execute(){
    if(paramsIsValid()){
        SlideMeneger::removePage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool RemovePage::paramsIsValid()
{
    return (getParams().integerArguments.size() == 1) && (!getParams().stringArguments.empty());
}

void OpenPage::execute(){
    if(paramsIsValid()){
        SlideMeneger::openPage(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool OpenPage::paramsIsValid()
{
    return (getParams().integerArguments.size() == 1) && (!getParams().stringArguments.empty());
}

void AddRectangle::execute(){
    if(paramsIsValid()){
        SlideMeneger::addRectangle(getParams().integerArguments[0], getParams().integerArguments[1], getParams().integerArguments[2], getParams().integerArguments[3]);
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool AddRectangle::paramsIsValid(){
    return (getParams().integerArguments.size() == 4) && (!getParams().stringArguments.empty());
}

void MoveVertical::execute(){
    if(paramsIsValid()){
        SlideMeneger::moveVertical(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool MoveVertical::paramsIsValid(){
    return (getParams().integerArguments.size() == 2) && (!getParams().stringArguments.empty());
}

void MoveHorizontal::execute(){
    if(paramsIsValid()){
        SlideMeneger::moveHorizontal(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool MoveHorizontal::paramsIsValid(){
    return (getParams().integerArguments.size() == 2) && (!getParams().stringArguments.empty());
}

void ChangeIthemLenghth::execute(){
    if(paramsIsValid()){
        SlideMeneger::changeIthemLength(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool ChangeIthemLenghth::paramsIsValid()
{
    return (getParams().integerArguments.size() == 2) && (!getParams().stringArguments.empty());
}

void ChangeIthemHeight::execute(){
    if(paramsIsValid()){
        SlideMeneger::changeIthemHeight(getParams().integerArguments[0], getParams().integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}
bool ChangeIthemHeight::paramsIsValid()
{
    return (getParams().integerArguments.size() == 2) && (!getParams().stringArguments.empty());
}

void RemoveIthem::execute(){
    if(paramsIsValid()){
        SlideMeneger::removeIthem(getParams().integerArguments.front());
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}
bool RemoveIthem::paramsIsValid()
{
    return (getParams().integerArguments.size() == 1) && (!getParams().stringArguments.empty());
}
