#pragma once 

#include "comand.h"

#include <memory>
#include  <unordered_map>


class ComandFactory{
public:
    void registorComand(const NameComand &comand, std::shared_ptr<IComand> iCmd);
    IComand createComand(const NameComand &comand);

private:
    std::unordered_map<NameComand, std::shared_ptr<IComand>> comandMap;

};