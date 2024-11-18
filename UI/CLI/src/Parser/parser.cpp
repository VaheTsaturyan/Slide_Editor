#include "parser.h"


void Parser::input(std::istream& is){
    this->lexsik_analizer.setString(is);
}
const std::vector<sToken> &Parser::getTokensList()
{
    return this->tokens;
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


/*


void Parser::registrComand(const NameComand &comand, std::shared_ptr<AComand> iCmd){
    comandCreater.registorComand(comand, iCmd);

}
void Parser::zeroState()
{
    tokens.clear();
    syntaxs_analizer.goToStartState();
    lexsik_analizer.zeroState();
}

*/