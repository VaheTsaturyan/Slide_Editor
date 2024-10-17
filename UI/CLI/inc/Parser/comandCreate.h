#pragma once 

#include "comand.h"

#include <memory>



class ComandFactory{
public:
    void registorComand(const Comand& comand, const IComand& iCmd);
    IComand& createComand(const std::vector<sToken>& tokens);
private:
    Comand&& generateCommandFromToken(const std::vector<sToken>& tokens);
    Params&& genereytParamsFromToken(const std::vector<sToken>& token);

private:
    std::unordered_map<Comand, std::shared_ptr<AComand>> comandMap;

};