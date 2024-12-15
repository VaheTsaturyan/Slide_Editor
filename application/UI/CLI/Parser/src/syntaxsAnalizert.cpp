#include "syntaxsAnalizer.h"

#include <stdexcept>


void StateMeneger::cangeState(const sToken& token){
    switch (activState){
    case eState::START:
        if(token.tokenType == eTokenType::WORD){
            activState = eState::CMAND;
            return;    
        }
        activState = eState::DEAD_STATE;
        break;
    case eState::CMAND:
        if(token.tokenType == eTokenType::WORD){return;}
        if(token.tokenType == eTokenType::OPTION){
            activState = eState::OPTION;
            return;
        }
        activState = eState::DEAD_STATE;
        break;
    case eState::OPTION :
        if(token.tokenType == eTokenType::ARGUMENT_NUMBER){
            activState = eState::ARGUMENT_NUMBER;
            return;
        }
        if(token.tokenType == eTokenType::ARGUMENT_WORD){
            activState = eState::ARGUMENT_WORD;
            return;
        }
        if(token.tokenType == eTokenType::TEXT){
            activState = eState::TEXT;
            return;
        }
        activState = eState::DEAD_STATE;
        break;
    case eState::ARGUMENT_NUMBER :
        if(token.tokenType == eTokenType::OPTION){
            activState = eState::OPTION;
            return;
        }
        if(token.tokenType == eTokenType::COMMA){
            activState = eState::ARGUMENT_NUMBER;
            return;
        }
        if(token.tokenType == eTokenType::ARGUMENT_NUMBER){
            activState = eState::ARGUMENT_NUMBER;
            return;
        }
        activState = eState::DEAD_STATE;
        break;
    case eState::ARGUMENT_WORD :
        if(token.tokenType == eTokenType::OPTION){
            activState = eState::OPTION;
            return;
        }
        if(token.tokenType == eTokenType::COMMA){
            activState = eState::ARGUMENT_WORD;
            return;
        }
        if(token.tokenType == eTokenType::ARGUMENT_WORD){
            activState = eState::ARGUMENT_WORD;
            return;
        }


        activState = eState::DEAD_STATE;
        break;
    case eState::TEXT :
        if(token.tokenType == eTokenType::OPTION){
            activState = eState::OPTION;
            return;
        }
        activState = eState::DEAD_STATE;
        break;
    }
    
}

eState StateMeneger::getAftomatState(){
    return activState;
}


void SyntaxsAnilizer::syntaxsAnaliz(const sToken& token){
    stateMeneger.cangeState(token);
    if(stateMeneger.getAftomatState() == eState::DEAD_STATE){
        throw std::runtime_error("CLI: SA -invalid comand !\n");
    }
}


/*
void StateMeneger::goToStartState(){
    activState = eState::START;
}

void SyntaxsAnilizer::setToken(const sToken& token){
    this->token = token;
}

void SyntaxsAnilizer::goToStartState(){
    stateMeneger.goToStartState();
}
*/
