#include "comandCreate.h"
#include <stdexcept>


void ComandFactory::registorComand(const Comand &comand, std::shared_ptr<IComand> iCmd){
    comandMap.emplace(comand, iCmd);
}


IComand& ComandFactory::createComand(const std::vector<sToken>& tokens){
    auto comand = comandMap.find(generateCommandFromToken());
    if(comand == comandMap.end()){  
        throw std::runtime_error("CLI: the command is not valid");
    }
    comand.setParams(std::move(genereytParamsFromToken()));
    return comand;
}






Comand&& ComandFactory::generateCommandFromToken(const std::vector<sToken>& tokens){
    Comand comand;
    for(auto token : tokens){
        if(token.tokenType == eTokenType::WORD){
            comand += token.tokenContent.get();
        }
        if(token.tokenType == eTokenType::ARGUMENT){
            comand += token.tokenContent.get();
        }
    }
    return std::move(comand);
}

params&& ComandFactory::genereytParamsFromToken(const std::vector<sToken>& tokens){
    Params params;
    for(auto token : tokens){
        if(token.tokenType == eTokenType::OPTION_NUMBER){
            params.integerArguments.push_back(token.tokenContent.get());
        }
        if(token.tokenType == eTokenType::OPTION_WORD){
            params.stringArguments.push_back(token.tokenContent.get());
        }
    }
    return std::move(params);
}





























