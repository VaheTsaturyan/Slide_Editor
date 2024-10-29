#include "parser.h"


void Parser::input(std::istream& is){
    this->lexsik_analizer.setString(is);
}

void Parser::registrComand(const NameComand &comand, std::shared_ptr<AComand> iCmd){
    comandCreater.registorComand(comand, iCmd);

}
void Parser::startProces()
{
    while( lexerAnaliz() != eTokenOrder::NULL_TOKEN){
        syntaxsAnaliz();
        addInTokenList(lexsik_analizer.getToken());
    }
    if(tokens.empty()){
        return;
    }
    comandCreater.createComand(tokens).execute();
    tokens.clear();
}

eTokenOrder Parser::lexerAnaliz(){
    if(lexsik_analizer.getTokenOrder() == eTokenOrder::NULL_TOKEN){
        return eTokenOrder::NULL_TOKEN;
    }
    lexsik_analizer.lexerAnaliz();
    return eTokenOrder::VALID;
}

void Parser::syntaxsAnaliz(){
    syntaxs_analizer.syntaxsAnaliz(lexsik_analizer.getToken());
}

void Parser::addInTokenList(const sToken& token){
    tokens.push_back(token);
}
