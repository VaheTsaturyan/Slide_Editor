#pragma once

#include "./outoutDivace.h"

#include <vector>
#include <memory>


class Loger{
public:
    static Loger& getLoger();
    void addDivace(std::shared_ptr<IOutputDivace> divace);

    void print(const std::string&  str);
private:
    Loger() = default;
private:
    std::vector<std::shared_ptr<IOutputDivace>> outputDivace;
};