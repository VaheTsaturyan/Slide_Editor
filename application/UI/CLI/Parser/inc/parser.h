#pragma once 

#include "lexer.h"
#include "syntaxsAnalizer.h"
#include "comandCreate.h"

#include <ostream>

class Parser{
public:
    void input(std::istream& is);
    void parsing();

    NameComand getComand();
    std::shared_ptr<Params> getParams();
    std::shared_ptr<Options> getOptions();

    
    //void registrComand(const NameComand& comand, std::shared_ptr<AComand> iCmd);
    //void zeroState();

private:
    eTokenOrder lexerAnaliz();
    void syntaxsAnaliz();
    void addInTokenList(const sToken& token);

private:
    std::vector<sToken> tokens; 
    Lexer lexsik_analizer;
    SyntaxsAnilizer syntaxs_analizer;
    //omandFactory comandCreater;
    
};