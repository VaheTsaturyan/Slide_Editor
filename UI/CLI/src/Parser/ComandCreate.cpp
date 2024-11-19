#include "comandCreate.h"
#include <stdexcept>


void ComandFactory::registorComand(const NameComand &comand, std::shared_ptr<AComand> iCmd){
    comandMap.emplace(comand, iCmd);
}


AComand& ComandFactory::createComand(const std::vector<sToken>& tokens){
    auto comand = comandMap.find(generateCommandFromToken(tokens));
    if(comand == comandMap.end()){  
        throw std::runtime_error("CLI: the command is not valid\n");
    }
    comand->second->setOptions(genereytOptionsFromToken(tokens));
    comand->second->setParams(genereytParamsFromToken(tokens));
    return *comand->second;
}






NameComand ComandFactory::generateCommandFromToken(const std::vector<sToken>& tokens){
    NameComand comand;
    for(auto token : tokens){
        if(token.tokenType == eTokenType::WORD){
            comand += std::get<word>(token.tokenContent);
        }
        /*
        if(token.tokenType == eTokenType::ARGUMENT){
            comand += std::get<word>(token.tokenContent);
        }
        */
    }
    return comand;
}

std::shared_ptr<Params> ComandFactory::genereytParamsFromToken(const std::vector<sToken>& tokens){
    std::shared_ptr<Params> params = std::make_shared<Params>();
    for(auto token : tokens){
        if(token.tokenType == eTokenType::OPTION_NUMBER){
            params->integerArguments.push_back(std::get<number>(token.tokenContent));
        }
        if(token.tokenType == eTokenType::OPTION_WORD){
            params->stringArguments.push_back(std::get<word>(token.tokenContent));
        }
    }
    return params;
}

std::shared_ptr<Options> ComandFactory::genereytOptionsFromToken(const std::vector<sToken> &tokens){
    std::shared_ptr<Options> params = std::make_shared<Options>();
    for(auto token : tokens){
        if(token.tokenType == eTokenType::ARGUMENT){
            params->push_back(std::get<word>(token.tokenContent));
        }
    }
    return params;
}
