#include "../inc/logger.h"



void Loger::addDivace(std::shared_ptr<IOutputDivace> divace){
    this->outputDivace.push_back(divace);
}

void Loger::print(const std::string &str){
    for(auto el : outputDivace){
        el->print(str);
    }
}

Loger &Loger::getLoger(){
    static Loger loger;
    return loger;
}
