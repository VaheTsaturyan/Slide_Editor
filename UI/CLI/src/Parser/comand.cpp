#include "comand.h"


void AComand::setParams(Params &&params){
    this->params.integerArguments = std::move(params.integerArguments);
    this->params.stringArguments = std::move(params.stringArguments)
}

const Params &AComand::getParams() const
{
    return params;
}




void NewComand::execute(){

}