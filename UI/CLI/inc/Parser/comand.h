#pragma once

#include "types.h"

#include <vector>

using Comand = std::string;

struct Params{
    std::vector<number> integerArguments;
    std::vector<word> stringArguments;
}; 


class AComand{
public:
    virtual ~AComand() = default;
    virtual void execute() = 0;
    void setParams(Params&& params);
    const Params& getParams() const;
private:
    Params params;
};

class NewComand : public AComand{
public:
    void execute() override;

private:
};


