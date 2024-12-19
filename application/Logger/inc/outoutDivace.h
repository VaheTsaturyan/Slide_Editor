#pragma once 
#include <string>
#include <ostream>

class IOutputDivace{
public:
    virtual ~IOutputDivace() = default;
    virtual void print(const std::string& str) = 0;
};

class OstreamDivace : public IOutputDivace{
public:
    OstreamDivace(std::ostream& out);
    void print(const std::string& str) override;
private:
    std::ostream& out;
};