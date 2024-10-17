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
    //void setToken(const sToken& token);
    bool syntaxsAnaliz(const sToken& token);
private:
    StateMeneger stateMeneger;
    //sToken token;
};


