#pragma once 

#include "comand.h"

#include <memory>
#include  <unordered_map>


class ComandFactory{
public:
    void registorComand(const KeyComand &comand, std::shared_ptr<AComand> iCmd);
    AComand& createComand(const std::vector<sToken>& tokens);
private:
    KeyComand&& generateCommandFromToken(const std::vector<sToken>& tokens);
    Params&& genereytParamsFromToken(const std::vector<sToken>& token);

private:
    std::unordered_map<KeyComand, std::shared_ptr<AComand>> comandMap;

};