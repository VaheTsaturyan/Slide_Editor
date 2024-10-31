#pragma once
#include "types.h"

class StateMeneger{
public:
    void cangeState(const sToken& token);
    eState getAftomatState();
    void goToStartState();
private:
   eState activState = eState::START;

};


class SyntaxsAnilizer{
public:

    void syntaxsAnaliz(const sToken& token);
    void goToStartState();
    
private:

    StateMeneger stateMeneger;
    
};


