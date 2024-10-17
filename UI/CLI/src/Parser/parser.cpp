#include "parser.h"

void Parser::input(std::istream& is){
    this->lexsik_analizer.setString(is);
}

void Parser::setOutputStream(std::ostream &os){
    this->os = os;
}
void Parser::startProces(){
    while(auto lexsResult = lexerAnaliz() != eTokenOrder::NULL_TOKEN)
    {
        if(lexsResult == eTokenOrder::INVALID){
            os<<"CLI: invalid comand !\n";
            return;
        }
        if(!syntaxsAnaliz()){
            os<<"CLI: invalid comand !\n";
            return;
        }
    }
    addInTokenList(lexsik_analizer.getToken());

    //if tokenList is no Empty return;
    //else comandCreaet(tokens)

}

eTokenOrder Parser::lexerAnaliz(){
    if(lexsik_analizer.getTokenOrder() == eTokenOrder::NULL_TOKEN){
        return eTokenOrder::NULL_TOKEN;
    }
    lexsik_analizer.lexerAnaliz();
    if(lexsik_analizer.getTokenOrder() == eTokenOrder::INVALID){
        return eTokenOrder::INVALID;
    }
    return eTokenOrder::VALID;
}

bool Parser::syntaxsAnaliz(){
    return syntaxs_analizer.syntaxsAnaliz(lexsik_analizer.getToken());

}

void Parser::addInTokenList(const sToken& token){
    tokens.push_back(token);
}
