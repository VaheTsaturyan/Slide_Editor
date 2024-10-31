#pragma once 

#include "comand.h"

#include <memory>
#include  <unordered_map>


class ComandFactory{
public:
    void registorComand(const NameComand &comand, std::shared_ptr<AComand> iCmd);
    AComand& createComand(const std::vector<sToken>& tokens);
private:
    NameComand generateCommandFromToken(const std::vector<sToken>& tokens);
    std::shared_ptr<Params> genereytParamsFromToken(const std::vector<sToken>& token);

private:
    std::unordered_map<NameComand, std::shared_ptr<AComand>> comandMap;

};