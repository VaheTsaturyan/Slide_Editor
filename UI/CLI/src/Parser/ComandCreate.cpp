#include "comandCreate.h"
#include <stdexcept>


void ComandFactory::registorComand(const KeyComand &comand, std::shared_ptr<AComand> iCmd){
    comandMap.emplace(comand, iCmd);
}


AComand& ComandFactory::createComand(const std::vector<sToken>& tokens){
    auto comand = comandMap.find(generateCommandFromToken(tokens));
    if(comand == comandMap.end()){  
        throw std::runtime_error("CLI: the command is not valid");
    }
    comand->second->setParams(std::move(genereytParamsFromToken(tokens)));
    return *comand->second;
}






KeyComand&& ComandFactory::generateCommandFromToken(const std::vector<sToken>& tokens){
    KeyComand comand;
    for(auto token : tokens){
        if(token.tokenType == eTokenType::WORD){
            comand += std::get<word>(token.tokenContent);
        }
        if(token.tokenType == eTokenType::ARGUMENT){
            comand += std::get<word>(token.tokenContent);
        }
    }
    return std::move(comand);
}

Params&& ComandFactory::genereytParamsFromToken(const std::vector<sToken>& tokens){
    Params params;
    for(auto token : tokens){
        if(token.tokenType == eTokenType::OPTION_NUMBER){
            params.integerArguments.push_back(std::get<number>(token.tokenContent));
        }
        if(token.tokenType == eTokenType::OPTION_WORD){
            params.stringArguments.push_back(std::get<word>(token.tokenContent));
        }
    }
    return std::move(params);
}





























