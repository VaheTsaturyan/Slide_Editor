#include "comandCreate.h"
#include <stdexcept>


void ComandFactory::registorComand(const NameComand &comand, std::shared_ptr<IComand> iCmd){
    comandMap.emplace(comand, iCmd);
}


IComand ComandFactory::createComand(const NameComand &comand){
    if(comand == comandMap.end()){  
        throw std::runtime_error("CLI: the command is not valid\n");
    }
    return *comand->second;
}




