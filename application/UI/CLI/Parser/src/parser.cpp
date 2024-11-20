#include "parser.h"


void Parser::input(std::istream& is){
    this->lexsik_analizer.setString(is);
}


void Parser::parsing()
{
    while( lexerAnaliz() != eTokenOrder::NULL_TOKEN){
        syntaxsAnaliz();
        addInTokenList(lexsik_analizer.getToken());
    }
    if(tokens.empty()){
        return;
    }
}


eTokenOrder Parser::lexerAnaliz(){
    lexsik_analizer.lexerAnaliz();
    if(lexsik_analizer.getTokenOrder() == eTokenOrder::NULL_TOKEN){
        return eTokenOrder::NULL_TOKEN;
    }
    return eTokenOrder::VALID;
}

void Parser::syntaxsAnaliz(){
    syntaxs_analizer.syntaxsAnaliz(lexsik_analizer.getToken());
}


void Parser::addInTokenList(const sToken& token){
    tokens.push_back(token);
}



std::shared_ptr<Params> Parser::getParams()
{
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


std::shared_ptr<Options> Parser::getOptions()
{
    std::shared_ptr<Options> params = std::make_shared<Options>();
    for(auto token : tokens){
        if(token.tokenType == eTokenType::ARGUMENT){
            params->push_back(std::get<word>(token.tokenContent));
        }
    }
    return params;
}



NameComand Parser::getComand()
{
    NameComand comand;
    for(auto token : tokens){
        if(token.tokenType == eTokenType::WORD){
            comand += std::get<word>(token.tokenContent);
        }
    }
    return comand;
}