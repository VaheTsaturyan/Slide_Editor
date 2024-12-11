#pragma once 

#include "lexer.h"
#include "syntaxsAnalizer.h"
#include "comandCreate.h"

#include <ostream>
#include <unordered_map>

class Parser{
public:
    void input(std::istream& is);
    void parsing();

    NameComand getComand();
    std::shared_ptr<std::unordered_map<Options, Params>> getOptionsValue();

    
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