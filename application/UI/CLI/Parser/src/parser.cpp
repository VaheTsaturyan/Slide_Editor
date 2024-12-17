#include "parser.h"

#include <iostream>

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

std::shared_ptr<std::unordered_map<Options, Params>> Parser::getOptionsValue()
{
    std::shared_ptr<std::unordered_map<Options, Params>> map = std::make_shared<std::unordered_map<Options, Params>>();
    Options option;
    Params params;
    bool bol = false;
    for(size_t i = 0; i < tokens.size(); ++i){
        if(tokens[i].tokenType == eTokenType::OPTION && !bol ){
            option = std::get<std::string>(tokens[i].tokenContent);
            bol = true;
        }else if(tokens[i].tokenType == eTokenType::OPTION) {
            map->emplace(option, params);
            params.vectorInteger.clear();
            params.vectorString.clear();
            option = std::get<std::string>(tokens[i].tokenContent);
        }else{
            if(tokens[i].tokenType == eTokenType::ARGUMENT_NUMBER){
                params.vectorInteger.push_back(std::get<int>(tokens[i].tokenContent));
            }
            if(tokens[i].tokenType == eTokenType::ARGUMENT_WORD){
                params.vectorString.push_back(std::get<std::string>(tokens[i].tokenContent));
            }
            if(tokens[i].tokenType == eTokenType::TEXT){
                params.vectorString.push_back(std::get<std::string>(tokens[i].tokenContent));
            }
        }
    }
    if(bol){
        map->emplace(option, params);
    }   

    return map;
    
}




/*
        {
            option = std::get<std::string>(tokens[i].tokenContent);
            ++i;
                while(i < tokens.size() && tokens[i].tokenType != eTokenType::OPTION){            
                if(tokens[i].tokenType == eTokenType::ARGUMENT_NUMBER){
                    params.vectorInteger.push_back(std::get<int>(tokens[i].tokenContent));
                }
                if(tokens[i].tokenType == eTokenType::ARGUMENT_WORD){
                    params.vectorString.push_back(std::get<std::string>(tokens[i].tokenContent));
                }

                ++i;
            }
            map->emplace(option, params);
        }

*/

