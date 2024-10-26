#pragma once 

#include "lexer.h"
#include "syntaxsAnalizer.h"
#include "comandCreate.h"

#include <ostream>

class Parser{
public:
    void input(std::istream& is);
    void startProces();
    void registrComand(const Comand& comand, std::shared_ptr<AComand> iCmd);
private:
    eTokenOrder lexerAnaliz();
    void syntaxsAnaliz();
    void addInTokenList(const sToken& token);
private:
    std::vector<sToken> tokens; 
    Lexer lexsik_analizer;
    SyntaxsAnilizer syntaxs_analizer;
    ComandFactory comandCreater;
    
};