#include "comand.h"


void AComand::setParams(Params &&params){
    this->params.integerArguments = std::move(params.integerArguments);
    this->params.stringArguments = std::move(params.stringArguments)
}

const Params &AComand::getParams() const
{
    return params;
}




void NewComand::execute(std::shared_ptr<Slide_Collection> sldColection){
    if(!paramsIsValid()){
        throw std::runtime_error("CLI: coma");
    }
    sldColection = std::make_shared<Slide_Collection>(); 
}

bool NewComand::paramsIsValid(){
    return !(getParams().integerArguments.empty() || getParams().stringArguments.empty());
}



void AddSlide::execute(std::shared_ptr<Slide_Collection> sldColection){
    if(!paramsIsValid()){
        throw std::runtime_error("CLI: coma");
    }
    Slide_Collection::Iterator  it = (*sldColection).begin();
    for(int i = 0 , i < getParams().getParams().integerArguments.front()){
        ++it;
    }
    (*sldColection).insert(it);
    
}

bool AddSlide::paramsIsValid()
{
    return (!getParams().stringArguments.empty() && getParams().integerArguments.size() == 1);
}