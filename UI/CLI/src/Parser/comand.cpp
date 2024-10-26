#include "comand.h"


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
    return !(params.integerArguments.empty() || params.stringArguments.empty());
}

void AddPage::execute(){
    if(paramsIsValid()){
        SlideMeneger::addPage(params.integerArguments.front());
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool AddPage::paramsIsValid()
{
    return (params.integerArguments.size() == 1) && (!params.stringArguments.empty());
}

void RemovePage::execute(){
    if(paramsIsValid()){
        SlideMeneger::removePage(params.integerArguments.front());
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool RemovePage::paramsIsValid()
{
    return return (params.integerArguments.size() == 1) && (!params.stringArguments.empty());
}

void OpenPage::execute(){
    if(paramsIsValid()){
        SlideMeneger::openPage(params.integerArguments.front());
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool OpenPage::paramsIsValid()
{
    return (params.integerArguments.size() == 1) && (!params.stringArguments.empty());
}

void AddRectangle::execute(){
    if(paramsIsValid()){
        SlideMeneger::addRectangle(params.integerArguments[0], params.integerArguments[1], params.integerArguments[2], params.integerArguments[3]);
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool AddRectangle::paramsIsValid(){
    return (params.integerArguments.size() == 4) && (!params.stringArguments.empty());
}

void MoveVertical::execute(){
    if(paramsIsValid()){
        SlideMeneger::moveVertical(params.integerArguments[0], params.integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool MoveVertical::paramsIsValid(){
    return (params.integerArguments.size() == 2) && (!params.stringArguments.empty());
}

void MoveHorizontal::execute(){
    if(paramsIsValid()){
        SlideMeneger::moveHorizontal(params.integerArguments[0], params.integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool MoveHorizontal::paramsIsValid(){
    return (params.integerArguments.size() == 2) && (!params.stringArguments.empty());
}

void ChangeIthemLenghth::execute(){
    if(paramsIsValid()){
        SlideMeneger::changeIthemLength(params.integerArguments[0], params.integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}

bool ChangeIthemLenghth::paramsIsValid()
{
    return (params.integerArguments.size() == 2) && (!params.stringArguments.empty());
}

void ChangeIthemHeight::execute(){
    if(paramsIsValid()){
        SlideMeneger::changeIthemHeight(params.integerArguments[0], params.integerArguments[1]);
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}
bool ChangeIthemHeight::paramsIsValid()
{
    return (params.integerArguments.size() == 2) && (!params.stringArguments.empty());
}

void RemoveIthem::execute(){
    if(paramsIsValid()){
        SlideMeneger::removeIthem(params.integerArguments.front());
    }else{
        throw std::runtime_error("CLI: the command is not valid");
    }
}
bool RemoveIthem::paramsIsValid()
{
    return (params.integerArguments.size() == 1) && (!params.stringArguments.empty());
}
