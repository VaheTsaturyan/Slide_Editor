#pragma once
#include "types.h"

class StateMeneger{
public:
    void cangeState(const sToken& token);
    eState getAftomatState();
private:
   eState activState = eState::START;

};


class SyntaxsAnilizer{
public:
    void syntaxsAnaliz(const sToken& token);
private:
    StateMeneger stateMeneger;
    
};


