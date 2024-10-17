#pragma once 

#include "lexer.h"
#include "syntaxsAnalizer.h"

#include <ostream>

class Parser{
public:
    void input(std::istream& is);
    void startProces();
    void setOutputStream(std::ostream& os);
private:
    eTokenOrder lexerAnaliz();
    bool syntaxsAnaliz();
    void addInTokenList(const sToken& token);
private:
    std::ostream& os;
    std::vector<sToken> tokens; 
    Lexer lexsik_analizer;
    SyntaxsAnilizer syntaxs_analizer;
    
};